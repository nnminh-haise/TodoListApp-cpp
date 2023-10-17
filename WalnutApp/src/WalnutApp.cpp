#include "Walnut/Application.h"
#include "Walnut/EntryPoint.h"
#include "Walnut/Image.h"

#include "App/Task.h"
#include "imgui-extend/imgui_stdlib.h"
#include <string>
#include <format>
#include <vector>

unsigned int Task::nextId = 1;

class TODOListApp : public Walnut::Layer {
public:
	void printTaskList() {
		enum ContentsType { CT_Text, CT_FillButton };
		static ImGuiTableFlags flags = ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg;

		ImGui::BeginTable("Todo list", 6, flags);
		ImGui::TableSetupColumn("Status");
		ImGui::TableSetupColumn("Title");
		ImGui::TableSetupColumn("Priority");
		ImGui::TableSetupColumn("Start date");
		ImGui::TableSetupColumn("Deadline");
		ImGui::TableSetupColumn("Note");
		ImGui::TableHeadersRow();

		for (Task task : tasks) {
			ImGui::TableNextRow();
			ImGui::TableSetColumnIndex(0);
			ImGui::Text(std::format("{}", Task::toString(task.getStatus())).c_str());
			ImGui::TableSetColumnIndex(1);
			ImGui::Text(std::format("{}", task.getTitle()).c_str());
			ImGui::TableSetColumnIndex(2);
			ImGui::Text(std::format("{}", Task::toString(task.getPriority())).c_str());
			ImGui::TableSetColumnIndex(3);
			ImGui::Text(std::format("{}", task.getStartDate().toString()).c_str());
			ImGui::TableSetColumnIndex(4);
			ImGui::Text(std::format("{}", task.getDeadline().toString()).c_str());
			ImGui::TableSetColumnIndex(5);
			ImGui::Text(std::format("{}", task.getNote()).c_str());
		}
		ImGui::EndTable();
	}

	virtual void OnUIRender() override {
		ImGui::Begin("TODO List");

		printTaskList();

		static int openTaskForm{};
		if (ImGui::Button("New Task")) { ++openTaskForm; }
		if (openTaskForm % 2) {
			Task newTask;
			if (getTask(newTask)) {
				this->tasks.emplace_back(newTask);
				openTaskForm++;
			}
		}
		

		ImGui::End();

		ImGui::ShowDemoWindow();
	}

private:
	bool getTask(Task& newTask) {
		bool formSubmit = false;
		static std::string title{};
		static std::string note{};

		ImGui::Begin("New Task");
		ImGui::InputTextMultiline("Title", &title, ImVec2(300, ImGui::GetTextLineHeight() * 1.5F));
		ImGui::InputTextMultiline("Note", &note, ImVec2(300, ImGui::GetTextLineHeight() * 1.5F));

		std::cout << title << std::endl;
		std::cout << note << std::endl;

		formSubmit = ImGui::Button("Submit");
		if (formSubmit) {
			newTask.setTitle(title);
			newTask.setNote(note);

			title.clear();
			note.clear();
		}
		ImGui::End();

		return formSubmit;
	}

private:
	std::vector<Task> tasks{};
};

Walnut::Application* Walnut::CreateApplication(int argc, char** argv) {
	Walnut::ApplicationSpecification spec;
	spec.Name = "TODO List Application";

	Walnut::Application* app = new Walnut::Application(spec);
	app->PushLayer<TODOListApp>();

	return app;
}