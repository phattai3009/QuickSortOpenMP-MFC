# Giới thiệu về đề tài QuickSortOpenMP-MFC
Xử lý và tính toán song song - Sắp xếp sinh viên theo tên bằng thuật toán quicksort và thư viện openMP - Parallel processing and computation - Sort students by name using quicksort algorithm and openMP library - MFC C++

## 1.1 Thế nào là lập trình, tính toán song song ?
Tính toán ss là sự thực hiện một cách đồng thời hai hoặc nhiều phép toán, công việc vào một thời điểm, được thực hiện bởi các bộ xử lý khác nhau.
## 1.2 Tại sao phải lập trình, tính toán song song ?
Theo xu hướng phát triển của công nghệ thông tin, các bộ xử lý đa nhân, đa lõi (multiple processor) đang dần dần thay thế các bộ xử lý đơn lõi (single processor) tuy nhiên với lối lập trình truyền thống (lập trình tuần tự), các câu lệnh, các quá trình xử lý được thực hịên một cách lần lượt, tuần tự như vậy sẽ không phát huy hết công năng, hiệu năng của bộ vi xử lý đa nhân, đa lõi (multiple processor). Lập trình, tính toán song song ra đời như một lời giải cho yêu cầu, thách thức đặt ra là làm thế nào để phát huy công năng, hiệu năng của bộ đa xử lý (multiple processor).
Trên thực tế, có rất nhiều bài toán với dữ liệu lớn, độ phức tạp tính toán cao mà đòi hỏi thời gian xử lý ngắn, độ chính xác cao. Vd: các bài toán liên  quan tới xử lý ảnh, xử lý tín hiệu, dự báo thời tiết, mô phỏng giao thông, mô phỏng sự chuyển động của các phân tử, nguyên tử, mô phỏng bản đồ gen, các bài toán liên quan đến cơ sở dữ liệu và khai thác cơ sở dữ liệu. . . với bộ xử lý đơn lõi thì khó có thể thực hiện và cho kết quả như mong muốn được.
Lập trình, tính toán song song là lời giải đáp cho bài toán tăng hiệu năng xử lý đồng thời rút ngắn thời gian xử lý tính toán của người dùng.

## 1.3 So sánh lập trình tính toán tuần tự và lập trình tính toán song song.
| Lập trình tính toán tuần tự          | Lập trình tính toán song song                   |
|---------------|--------------------------|
| 
	Chương trình ứng dụng chạy trên bộ xử lý đơn (single processor).
	Các chỉ thị lệnh được bộ xử lý (CPU) thực hiện một cách lần lượt, tuần tự.
	Mỗi chỉ thị lệnh chỉ thực thiện trên duy nhất một thành phần dữ liệu.
	Lập trình viên chỉ cần đảm  bảo viết đúng mã lệnh theo giải thuật chương trình là chương trình có thể dịch, chạy và cho ra kết quả.
	Thường được áp dụng đối với các bài toán có dữ liệu nhỏ, độ phức tạp bình thường và thời
gian cho phép.                                                                                                                        | 	Chương trình ứng dụng chạy trên hai hoặc nhiều bộ xử lý.
	Các chỉ thị lệnh được các bộ vi xử lý thực hiện một cách song song, đồng thời.
	Mỗi chỉ thị lệnh có thể thao tác trên hai hoặc nhiều thành phần dữ liệu khác nhau.
	Ngoài việc đảm bảo viết đúng mã lệnh theo giải thuật, lập trình viên còn phải chỉ ra trong chương trình đoạn mã nào được thực hiện song song, đồng thời.
	Thường được áp dụng đối với các bài toán có dữ liệu lớn, độ phức tạp cao và thời gian ngắn.
 |
