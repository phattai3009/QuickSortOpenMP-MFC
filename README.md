# Giới thiệu về đề tài QuickSortOpenMP-MFC
Xử lý và tính toán song song - Sắp xếp sinh viên theo tên bằng thuật toán quicksort và thư viện openMP - Parallel processing and computation - Sort students by name using quicksort algorithm and openMP library - MFC C++

## 1.1 Thế nào là lập trình, tính toán song song ?
Tính toán ss là sự thực hiện một cách đồng thời hai hoặc nhiều phép toán, công việc vào một thời điểm, được thực hiện bởi các bộ xử lý khác nhau.
## 1.2 Tại sao phải lập trình, tính toán song song ?
Theo xu hướng phát triển của công nghệ thông tin, các bộ xử lý đa nhân, đa lõi (multiple processor) đang dần dần thay thế các bộ xử lý đơn lõi (single processor) tuy nhiên với lối lập trình truyền thống (lập trình tuần tự), các câu lệnh, các quá trình xử lý được thực hịên một cách lần lượt, tuần tự như vậy sẽ không phát huy hết công năng, hiệu năng của bộ vi xử lý đa nhân, đa lõi (multiple processor). Lập trình, tính toán song song ra đời như một lời giải cho yêu cầu, thách thức đặt ra là làm thế nào để phát huy công năng, hiệu năng của bộ đa xử lý (multiple processor).
Trên thực tế, có rất nhiều bài toán với dữ liệu lớn, độ phức tạp tính toán cao mà đòi hỏi thời gian xử lý ngắn, độ chính xác cao. Vd: các bài toán liên  quan tới xử lý ảnh, xử lý tín hiệu, dự báo thời tiết, mô phỏng giao thông, mô phỏng sự chuyển động của các phân tử, nguyên tử, mô phỏng bản đồ gen, các bài toán liên quan đến cơ sở dữ liệu và khai thác cơ sở dữ liệu. . . với bộ xử lý đơn lõi thì khó có thể thực hiện và cho kết quả như mong muốn được.
Lập trình, tính toán song song là lời giải đáp cho bài toán tăng hiệu năng xử lý đồng thời rút ngắn thời gian xử lý tính toán của người dùng.

## 1.3 So sánh lập trình tính toán tuần tự và lập trình tính toán song song.

![image](https://user-images.githubusercontent.com/83421255/174756645-cc6cfabe-1e6d-4b46-a3e0-ca20281e09fb.png)

