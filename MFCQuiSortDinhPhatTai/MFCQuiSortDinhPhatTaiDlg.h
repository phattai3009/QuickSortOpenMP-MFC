
// MFCQuiSortDinhPhatTaiDlg.h : header file
//

#pragma once


// CMFCQuiSortDinhPhatTaiDlg dialog
class CMFCQuiSortDinhPhatTaiDlg : public CDialogEx
{
// Construction
public:
	CMFCQuiSortDinhPhatTaiDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCQUISORTDINHPHATTAI_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CEdit tb_N;
	CStatic m_time1;
	CStatic m_time2;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	CStatic m_banghi;
	afx_msg void OnEnChangeThreads();
	
	CComboBox m_threads;
	CStatic m_filepath;
	CButton m_hienthiDL;
	afx_msg void OnBnClickedButton5();
	CListCtrl m_list1;
	CListCtrl m_list2;
	CListCtrl m_list3;
	CListCtrl m_list4;
	afx_msg void OnBnClickedBttgoc();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnStnClickedHduongdan();
};
