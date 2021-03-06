
// MFCQuiSortDinhPhatTaiDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCQuiSortDinhPhatTai.h"
#include "MFCQuiSortDinhPhatTaiDlg.h"
#include "afxdialogex.h"
//#pragma once
#include <math.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#define MAXX 700000
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
using namespace std;


struct sinhvien {
	int masv; // ma so sinh vien
	string tensv;
	string gioitinh;
	int tuoi;
};

//=============================================================

void quickSort_parallel(sinhvien* array, int lenArray, int numThreads);
void quickSort_parallel_internal(sinhvien* array, int left, int right, int cutoff);



void quickSort_parallel(sinhvien* array, int lenArray, int numThreads) {

	int cutoff = 1000;

#pragma omp parallel num_threads(numThreads)
	{
#pragma omp single nowait
		{
			quickSort_parallel_internal(array, 0, lenArray - 1, cutoff);
		}
	}

}



void quickSort_parallel_internal(sinhvien* array, int left, int right, int cutoff)
{

	int i = left, j = right;
	sinhvien tmp;
	int pivot = array[(left + right) / 2].masv;
	{
		while (i <= j) {
			while (array[i].masv < pivot)
				i++;
			while (array[j].masv > pivot)
				j--;
			if (i <= j) {
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				i++;
				j--;
			}
		}

	}
	if (((right - left) < cutoff)) {
		if (left < j) { quickSort_parallel_internal(array, left, j, cutoff); }
		if (i < right) { quickSort_parallel_internal(array, i, right, cutoff); }

	}
	else {
#pragma omp task 	
		{ quickSort_parallel_internal(array, left, j, cutoff); }
#pragma omp task 	
		{ quickSort_parallel_internal(array, i, right, cutoff); }
	}

}
//==============================================================


sinhvien ds[MAXX], ds1[MAXX], ds2[MAXX];
int N; // số phần tử sắp xếp được đọc từ textbox
void xuly1dong(string line, sinhvien &a);
// Comparator used in qsort()
int cmpfunc(const void* a, const void* b)
{
	
		sinhvien* orderA = (sinhvien*)a;
		sinhvien* orderB = (sinhvien*)b;

		return (orderB->masv - orderA->masv);
	
}


// x gan bang y
void Bang(sinhvien& x, sinhvien y)
{
	x.masv = y.masv;
	x.tensv = y.tensv;
	x.gioitinh = y.gioitinh;
	x.tuoi = y.tuoi;
}
void docfile(string file, int N)
{
	fstream f;
	f.open(file, ios::in);

	string data;
	int i = 0;
	sinhvien a;
	//while (!f.eof())
	for(int dong = 0; dong < N;dong++)
	{
		getline(f, data);
		if (data != "")
		{
			xuly1dong(data, ds[i]);
			i++;
		}
		
		
	}
	f.close();
}

void xuly1dong(string line, sinhvien &a)
{
	
	string res = "";
	int i = 0, len = line.length();
	// lay ma sinh vien
	while (i < len && line[i] != '|')
	{
		res += line[i];
		i++;
	}
	a.masv = stoi(res);
	res = "";
	i++;
	// doc ten sinh vien
	while (i < len && line[i] != '|')
	{
		res += line[i];
		i++;
	}
	a.tensv = res;
	res = "";
	i++;
	// doc gioi tinh
	while (i < len && line[i] != '|')
	{
		res += line[i];
		i++;
	}
	a.gioitinh = res;
	res = "";
	i++;
	// lay tuoi
	while (i < len && line[i] != '|')
	{
		res += line[i];
		i++;
	}
	a.tuoi = stoi(res);
}
void swapSV(sinhvien &x, sinhvien &y)
{
	sinhvien temp;
	temp.masv = x.masv;
	temp.tensv = x.tensv;
	temp.gioitinh = x.gioitinh;
	temp.tuoi = x.tuoi;

	x.masv = y.masv;
	x.tensv = y.tensv;
	x.gioitinh = y.gioitinh;
	x.tuoi = y.tuoi;

	y.masv = temp.masv;
	y.tensv = temp.tensv;
	y.gioitinh = temp.gioitinh;
	y.tuoi = temp.tuoi;
}
// THUẬT TOÁN
int partition(sinhvien arr[], int low, int high) {
	int i, j, temp, key;
	key = arr[low].masv;
	i = low + 1;
	j = high;
	while (1) {
		while (i < high && key >= arr[i].masv)
			i++;
		while (key < arr[j].masv)
			j--;
		if (i < j) {
			/*temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;*/
			swap(arr[i], arr[j]);
		}
		else {
			/*temp = arr[low];
			arr[low] = arr[j];
			arr[j] = temp;*/
			swap(arr[low], arr[j]);
			return(j);
		}
	}
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low  --> Starting index,
high  --> Ending index */
void quicksort(sinhvien arr[], int low, int high)
{
	int j;
	if (low < high) {
		j = partition(arr, low, high);
		quicksort(arr, low, j - 1);
		quicksort(arr, j + 1, high);
	}
}

/*-----------------------------------------------------------------------------*/
int partition2(sinhvien arr[], int low, int high) {
	int i, j, temp, key;
	key = arr[low].masv;
	i = low + 1;
	j = high;
	while (1) {
		while (i < high && key >= arr[i].masv)
			i++;
		while (key < arr[j].masv)
			j--;
		if (i < j) {
			/*temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;*/
			swapSV(arr[i], arr[j]);
		}
		else {
			/*temp = arr[low];
			arr[low] = arr[j];
			arr[j] = temp;*/
			swapSV(arr[low], arr[j]);
			return(j);
		}
	}
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low  --> Starting index,
high  --> Ending index */
void quicksort2(sinhvien arr[], int low, int high)
{
	int j;
	if (low < high) {
		j = partition2(arr, low, high);
#pragma omp parallel sections //Khởi tạo vùng song song
		{
#pragma omp section //Khởi tạo luồng 1
			{
				quicksort2(arr, low, j - 1);//Thread 1
			}
#pragma omp section //Khởi tạo luồng 2
			{
				quicksort2(arr, j + 1, high);//Thread 2
			}
		}
	}
}

void quicksortv2(sinhvien arr2[], int x)
{
	int j = partition(arr2, 0, x - 1);// Trả về giá trị của phần tử chốt

#pragma omp parallel sections //Khởi tạo vùng song song
	{
#pragma omp section //Khởi tạo luồng 1
		{
			quicksort(arr2, 0, j - 1);//Thread 1
		}
#pragma omp section //Khởi tạo luồng 2
		{
			quicksort(arr2, j + 1, x - 1);//Thread 2
		}
	}
}
// Lấy trái (đầu tiên) mảng và lấy phải (cuối) mảng
void quickSortThuong(sinhvien Data[], int l, int r)
{
	//Nếu gt đầu tiên nhở hơn gt cuối cùng
	if (l <= r)
	{
		//tạo k chứ mảng.
		int key = Data[(l + r) / 2].masv;

		//tạo biến tạm
		int i = l;
		int j = r;

		while (i <= j)
		{
			while (Data[i].masv < key)
				i++;
			while (Data[j].masv > key)
				j--;

			if (i <= j)
			{
				swap(Data[i], Data[j]);
				i++;
				j--;
			}
		}

		//Đệ quy phần tử nhỏ trong mảng sau khi được sắp xếp ở trên

		if (l < j)
			quickSortThuong(Data, l, j);
		if (r > i)
			quickSortThuong(Data, i, r);
	}
}
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCQuiSortDinhPhatTaiDlg dialog



CMFCQuiSortDinhPhatTaiDlg::CMFCQuiSortDinhPhatTaiDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCQUISORTDINHPHATTAI_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCQuiSortDinhPhatTaiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, tb_N);
	DDX_Control(pDX, IDC_TIME1, m_time1);
	DDX_Control(pDX, IDC_TIME2, m_time2);
	DDX_Control(pDX, IDC_COMBO1, m_threads);
	DDX_Control(pDX, IDC_HDUONGDAN, m_filepath);
	DDX_Control(pDX, IDC_CHECK1, m_hienthiDL);
	DDX_Control(pDX, IDC_LIST2, m_list1);
	DDX_Control(pDX, IDC_LIST3, m_list2);
	DDX_Control(pDX, IDC_LIST1, m_list3);
	DDX_Control(pDX, IDC_LIST4, m_list4);
}

BEGIN_MESSAGE_MAP(CMFCQuiSortDinhPhatTaiDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCQuiSortDinhPhatTaiDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCQuiSortDinhPhatTaiDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCQuiSortDinhPhatTaiDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCQuiSortDinhPhatTaiDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BTTGOC, &CMFCQuiSortDinhPhatTaiDlg::OnBnClickedBttgoc)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCQuiSortDinhPhatTaiDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCQuiSortDinhPhatTaiDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDCANCEL, &CMFCQuiSortDinhPhatTaiDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_CHECK1, &CMFCQuiSortDinhPhatTaiDlg::OnBnClickedCheck1)
	ON_STN_CLICKED(IDC_HDUONGDAN, &CMFCQuiSortDinhPhatTaiDlg::OnStnClickedHduongdan)
END_MESSAGE_MAP()


// CMFCQuiSortDinhPhatTaiDlg message handlers

BOOL CMFCQuiSortDinhPhatTaiDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	tb_N.SetWindowTextW(_T("1000"));
	CString str;
	for (int i = 2; i < 10;)
	{
		int n;
		str.Format(_T("%d"), i);
		n = m_threads.AddString(str);
		m_threads.SetItemData(n, i);
		i = i * 2;
	}
	str.Format(_T("2"));
	m_threads.SetWindowTextW(str);
	m_filepath.SetWindowTextW(_T("Load dữ liệu file .txt"));

	m_list1.InsertColumn(0, L"Mã sinh viên", LVCFMT_LEFT, 90);
	m_list1.InsertColumn(1, L"Tên sinh viên", LVCFMT_LEFT, 120);
	m_list1.InsertColumn(2, L"Giới tính", LVCFMT_LEFT, 60);
	m_list1.InsertColumn(3, L"Tuổi", LVCFMT_LEFT, 40);

	m_list2.InsertColumn(0, L"Mã SV", LVCFMT_LEFT, 90);
	m_list2.InsertColumn(1, L"Tên sinh viên", LVCFMT_LEFT, 120);
	m_list2.InsertColumn(2, L"Giới tính", LVCFMT_LEFT, 60);
	m_list2.InsertColumn(3, L"Tuổi", LVCFMT_LEFT, 40);


	m_list3.InsertColumn(0, L"Mã SV", LVCFMT_LEFT, 90);
	m_list3.InsertColumn(1, L"Tên sinh viên", LVCFMT_LEFT, 120);
	m_list3.InsertColumn(2, L"Giới tính", LVCFMT_LEFT, 60);
	m_list3.InsertColumn(3, L"Tuổi", LVCFMT_LEFT, 40);

	m_list4.InsertColumn(0, L"N", LVCFMT_LEFT, 60);
	m_list4.InsertColumn(1, L"Quick Sort", LVCFMT_LEFT, 80);
	m_list4.InsertColumn(2, L"Parallel Quick Sort", LVCFMT_LEFT, 120);
	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCQuiSortDinhPhatTaiDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCQuiSortDinhPhatTaiDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCQuiSortDinhPhatTaiDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

CString sFilePath;

CString convert_StringTo_Cstring(string str)
{
	CString res;
	for (int i = 0; i < str.length(); i++)
		res += str[i];
	return res;
}
string convert_Cstring_to_String(CString str)
{
	string res;
	for (int i = 0; i < str.GetLength(); i++)
	{
		res += str[i];
	}
	return res;
}
void CMFCQuiSortDinhPhatTaiDlg::OnBnClickedButton1()
{
	// doc file goc

	// lay gia tri n
	CString s1;
	tb_N.GetWindowText(s1);
	std::wstring s((LPCTSTR)s1);
	if (s1.GetLength() <= 0)
	{
		MessageBox(L"Hãy nhập giá trị N", L"Thông báo");
		return;
	}

	N = std::stod(s);
	if (N <= 0) N = 1000;

	const TCHAR szFilter[] = _T("txt Files (*.txt)|*.txt|All Files (*.*)|*.*||");
	CFileDialog dlg(FALSE, _T("txt"), NULL, OFN_HIDEREADONLY, szFilter, this);
	if (dlg.DoModal() == IDOK)
	{
		sFilePath = dlg.GetPathName();
		m_filepath.SetWindowText(sFilePath);
	}

	docfile(convert_Cstring_to_String(sFilePath),N);
	MessageBox(_T("Load dữ liệu thành công!"),_T("Thông báo"));
	// TODO: Add your control notification handler code here
}


void CMFCQuiSortDinhPhatTaiDlg::OnBnClickedButton3()
{
	// lay gia tri n
	CString s1;
	tb_N.GetWindowText(s1);
	std::wstring s((LPCTSTR)s1);
	if (s1.GetLength() <= 0)
	{
		MessageBox(L"Hãy nhập giá trị N", L"Thông báo");
		return;
	}

	N = std::stod(s);
	if (N <= 0) N = 1000;
	for (int i = 0; i < N; i++)
	{
		Bang(ds1[i], ds[i]);
	}
	int start_s = clock();//start SortTime

	quickSortThuong(ds1, 0, N-1);
	int stop_s = clock();//end sortTime
				 /*----------------------------------*/

	double timeuse = (double)(stop_s - start_s) / CLOCKS_PER_SEC;

	CString strValue;
	strValue.Format(_T("%f s"), timeuse);
	m_time1.SetWindowTextW(strValue);
	
	if (m_hienthiDL.GetCheck() == true)
	{
		CString str1, str2, ss;
		int nItem;
		int len = min(1000, N);
		for (int i = len-1; i >=0; i--)
		{
			ss.Format(_T("%d"), ds1[i].masv);
			nItem = m_list2.InsertItem(0, ss);
			m_list2.SetItemText(nItem, 1, convert_StringTo_Cstring(ds1[i].tensv));
			m_list2.SetItemText(nItem, 2, convert_StringTo_Cstring(ds1[i].gioitinh));
			ss.Format(_T("%d"), ds1[i].tuoi);
			m_list2.SetItemText(nItem, 3, ss);
		}
	}
}


void CMFCQuiSortDinhPhatTaiDlg::OnBnClickedButton4()
{
	// lay gia tri n
	CString s1;
	tb_N.GetWindowText(s1);
	std::wstring s((LPCTSTR)s1);
	if (s1.GetLength() <= 0)
	{
		MessageBox(L"Hãy nhập giá trị N", L"Thông báo");
		return;
	}

	N = std::stod(s);
	if (N <= 0) N = 1000;
	for (int i = 0; i < N; i++)
	{
		Bang(ds2[i], ds[i]);
	}
	
	CString s2;
	m_threads.GetWindowText(s2);
	std::wstring sa((LPCTSTR)s2);
	if (s2.GetLength() <= 0)
	{
		MessageBox(L"Hãy nhập giá trị threads", L"Thông báo");
		return;
	}

	int nthre = std::stod(sa);
	if (nthre <= 0) nthre = 2;
	int start_s = clock();//start SortTime
	//quicksortv2(ds2, N);
	quickSort_parallel(ds2, N, nthre);
	int stop_s = clock();//end sortTime
				 /*----------------------------------*/
	double timeuse = (double)(stop_s - start_s) / CLOCKS_PER_SEC;
	CString strValue;
	strValue.Format(_T("%f s"), timeuse);
	m_time2.SetWindowTextW(strValue);
	if (m_hienthiDL.GetCheck() == true)
	{
		CString str1, str2, ss;
		int nItem;
		int len = min(1000, N);
		for (int i = len-1; i >=0; i--)
		{
			ss.Format(_T("%d"), ds2[i].masv);
			nItem = m_list3.InsertItem(0, ss);
			m_list3.SetItemText(nItem, 1, convert_StringTo_Cstring(ds2[i].tensv));
			m_list3.SetItemText(nItem, 2, convert_StringTo_Cstring(ds2[i].gioitinh));
			ss.Format(_T("%d"), ds2[i].tuoi);
			m_list3.SetItemText(nItem, 3, ss);
		}
	}
}


void CMFCQuiSortDinhPhatTaiDlg::OnEnChangeThreads()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CMFCQuiSortDinhPhatTaiDlg::OnBnClickedButton5()
{
	m_list1.DeleteAllItems();
	m_list2.DeleteAllItems();
	m_list3.DeleteAllItems();
	CString strValue;
	m_time1.SetWindowTextW(strValue);
	m_time2.SetWindowTextW(strValue);
	m_list4.DeleteAllItems();
	// TODO: Add your control notification handler code here
}




void CMFCQuiSortDinhPhatTaiDlg::OnBnClickedBttgoc()
{
	m_list1.DeleteAllItems();
	CString str1, str2, s;
	int nItem;
	int len = min(1000, N);
	for (int i = len-1; i >=0; i--)
	{
		s.Format(_T("%d"), ds[i].masv);
		nItem = m_list1.InsertItem(0, s);
		m_list1.SetItemText(nItem, 1, convert_StringTo_Cstring(ds[i].tensv));
		m_list1.SetItemText(nItem, 2, convert_StringTo_Cstring(ds[i].gioitinh));
		s.Format(_T("%d"), ds[i].tuoi);
		m_list1.SetItemText(nItem, 3, s);
	}
	
	// TODO: Add your control notification handler code here
}


void CMFCQuiSortDinhPhatTaiDlg::OnBnClickedButton2()
{
	CString str1, str2, s;
	s.Format(_T("%d"), N);
	int nItem = m_list4.InsertItem(0, s);

	m_time1.GetWindowTextW(str1);
	m_list4.SetItemText(nItem, 1, str1);

	m_time2.GetWindowTextW(str2);
	m_list4.SetItemText(nItem, 2, str2);
	// TODO: Add your control notification handler code here
}


void CMFCQuiSortDinhPhatTaiDlg::OnBnClickedButton7()
{
	CFileDialog dlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT,
		_T("My Data File (*.txt)|*.txt||"));
	if (dlg.DoModal() != IDOK)
		return;
	CString filename = dlg.GetPathName();
	ofstream outfile(filename);
	int mydata = 10;
	outfile << "Copyright by Dinh Phat Tai"<<endl;
	outfile << "N = " << N << endl;
	
	CString s2;
	m_threads.GetWindowText(s2);
	std::wstring sa((LPCTSTR)s2);
	int nthre = std::stod(sa);
	if (nthre <= 0) nthre = 2;
	outfile << "So Threads: " << nthre << endl;
	
	CString s;
	m_time1.GetWindowTextW(s);
	outfile << "Thoi gian chay Quick Sort binh thuong: " << convert_Cstring_to_String(s) << endl;
	m_time2.GetWindowTextW(s);
	outfile << "Thoi gian chay Parallel Quick Sort : " << convert_Cstring_to_String(s) << endl;
	outfile << "Du lieu sau khi sap xep: " << endl;
	for (int i = 0; i < N; i++)
	{
		outfile << ds1[i].masv << "|" << ds1[i].tensv << "|" << ds1[i].gioitinh << "|" << ds1[i].tuoi<<"|" << endl;
	}
	outfile.close();
	MessageBox(_T("Lưu File kết quả thành công"), _T("Thông báo"));
	// TODO: Add your control notification handler code here
}


void CMFCQuiSortDinhPhatTaiDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	if (MessageBox(L"Bạn có muốn thoát không?", L"Thông báo", MB_YESNO) == IDYES)
	{
		CDialogEx::OnCancel();
	}
}


void CMFCQuiSortDinhPhatTaiDlg::OnBnClickedCheck1()
{
	// TODO: Add your control notification handler code here
}


void CMFCQuiSortDinhPhatTaiDlg::OnStnClickedHduongdan()
{
	// TODO: Add your control notification handler code here
}
