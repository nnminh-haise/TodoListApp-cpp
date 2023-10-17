
# A Simple To Do List Application

---

> *Ứng dụng quản lí đầu việc cho phép người dùng thêm, tìm kiếm, thống kê và sắp xếp các đầu việc theo trạng thái, mức độ quan trọng, thời gian lên lịch và deadline. Có chức năng lọc và ghi đầu việc ra file văn bản. Đánh giá chủ yếu dựa trên thuật toán và tối ưu hoá dữ liệu, giao diện là điểm cộng.*

---

## Chức năng cơ bản

Ứng dụng quản lí đầu việc sẽ cho phép người dùng thêm/xoá/sửa những đầu việc cần làm, mỗi đầu việc sẽ có các yếu tố như:

- Trạng thái
    
    Gồm các trạng thái cụ thể như sau:
    
    - Chưa hoàn thành
    - Đang làm
    - Hoàn thành
    - Bị huỷ (vì nhiều lí do như không cần thiết, hoặc không làm nữa)
    - Quá hạn (quá thời gian hoàn thành)
    
    Mỗi đầu việc sẽ chỉ có một trạng thái duy nhất.
    
- Tiêu đề
    
    Gồm một chuỗi các kí tự không quá 100 kí tự (có thể tuỳ chỉnh giới hạn tuỳ ý).
    
- Mức độ quan trọng (mức độ ưu tiên)
    
    Gồm 5 mức độ quan trọng như sau:
    
    - Xong trong ngày
    - Xong trong ba ngày
    - Xong trong tuần
    - Xong trong hai tuần
    - Xong trong tháng
    
    Mỗi đầu việc chỉ có một trạng thái duy nhất.
    
- Thời gian lên lịch (ngày hiện tại)
    
    Định dạng: DD/MM/YYYY. Ví dụ: 12/10/2002.
    
- Thời gian hoàn thành (deadline - theo ngày)
    - Định dạng: DD/MM/YYYY. Ví dụ: 12/10/2002.
    - Thời gian hoàn thành phải bằng hoặc sau thời gian lên lịch.
- Ghi chú
    
    Gồm chuỗi các kí tự không quá 1000 kí tự (có thể tuỳ chỉnh giới hạn tuỳ ý).
    

***Bảng ví dụ mình hoạ:***

| Trạng thái | Tiêu đề | Mức độ quan trọng | Thời gian lên lịch | Thời gian hoàn thành | Ghi chú |
| --- | --- | --- | --- | --- | --- |
| Chưa hoàn thành | Công việc 1 | Trong ngày | 12/10/2002 | 24/12/2022 | Ghi chú ngắn |
| Đang làm | Công việc 2 | Trong ba ngày | 13/10/2002 | 25/12/2022 | Ghi chú ngắn |
| Hoàn thành | Công việc 3 | Trong tuần | 14/10/2002 | 26/12/2022 | Ghi chú ngắn |
| Bị huỷ | Công việc 4 | Trong hai tuần | 15/10/2002 | 27/12/2022 | Ghi chú ngắn |
| Quá hạn | Công việc 5 | Trong tháng | 16/10/2002 | 28/12/2022 | Ghi chú ngắn |
| Đang làm | Công việc 6 | Trong Tuần | 17/10/2002 | 29/12/2022 | Ghi chú ngắn |

## **Chức năng khác của ứng dụng**

1. Ứng dụng cho phép người dùng tìm kiếm những đầu việc đã có trong danh sách.
2. Có các tính năng thống kê số lượng đầu việc đã hoàn thành, chưa làm, bị huỷ, theo các trạng thái sẵn có.
3. Cho phép sắp xếp theo mức độ quan trọng của các đầu việc.
4. Ứng dụng cho phép ghi các đầu việc ra file văn bản định dạng `.txt` và đọc đầu việc từ file văn bản.
5. Chức năng lọc, chọn một số các đầu việc thoả mãn các tiêu chí.
    - Lọc theo trạng thái
    - Lọc theo ngày bất kì
    - Lọc mức độ quan trọng
    
    Ví dụ: Lọc các đầu việc phải xong trong ngày (xong trong 2 - 3 ngày, vân vân)
    
    Ví dụ: Lọc các đầu việc chưa xong.
    
    Ví dụ: Lọc các đầu việc phải xong trong ngày 12/10/2002.
    

---

## **Ghi chú về quá trình làm bài**

1. Không giới hạn các công nghệ được sử dụng
2. Không giới hạn định dạng file
3. Tối ưu hoá các chức năng về thời gian và bộ nhớ sử dụng
4. Thiết kế giao diện trên console hoặc đồ hoạ đều được, miễn tối ưu tốt.
5. Tiêu chí đánh giá chủ yếu qua thuật toán và cách tối ưu hoá dữ liệu. Giao diện là điểm cộng, tối đa 1.

---

## **Tiêu chí đánh giá**

- Các yêu cầu cơ bản ban đầu **phải** được hoàn thành đủ.
- Các chức năng khác của ứng dụng, mỗi chức năng sẽ có 2đ. Hoàn thành đủ 5 chức năng sẽ được 10 điểm.
- Đồ hoạ đẹp, giao diện đẹp sẽ có 1đ cộng, nếu đủ 10 điểm sẽ không tính thêm.

---

***Gợi ý:*** dành cho những bạn không biết quá nhiều về các ngôn ngữ lập trình khác hay các thư viện. MÌnh gợi ý hai thư viện về đồ hoạ trong C++ để hỗ trợ bạn làm đồ hoạ nếu bạn muốn, hoặc bạn có thể làm đồ hoạ đơn giản trên console.

- Thư viện đồ hoạ `Graphics.h`
    - Link tải thư viện: [ahuynh359/Graphics: Implement graphics library in Visual Studio (github.com)](https://github.com/ahuynh359/Graphics)
    - Link tài liệu: [Borland Graphics Interface (BGI) Documentation (colorado.edu)](https://home.cs.colorado.edu/~main/bgi/doc/)
- Thư viện `Dear ImGui`
    - Link tải thư viện: [ocornut/imgui: Dear ImGui: Bloat-free Graphical User interface for C++ with minimal dependencies (github.com)](https://github.com/ocornut/imgui)
    - Link tài liệu
        - [BEST WAY to make Desktop Applications in C++ - YouTube](https://www.youtube.com/watch?v=vWXrFetSH8w)
        - [(282) Make your own GUI apps in C++ (with ImGui and Vulkan) - YouTube](https://www.youtube.com/watch?v=5zS-DZhCA2g)

Các thư viện trong các ngôn ngữ lập trình được thoải mái sử dụng, không giới hạn.

Có thể làm trên nền tảng web, app hoặc mobile app.

---

## Ứng dụng

Ứng dụng sử dụng C++ với framework Wallnut để làm GUI.
