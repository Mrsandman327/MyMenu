#pragma once


// CMyMenu
class CMyMenu : public CMenu
{
public:
	CMyMenu();
	virtual ~CMyMenu();
private:
	struct SItem{
		UINT hImg;
		char szText[32];
		int nHeight;
	};
	CMap<WORD,WORD,SItem,SItem> m_map;//�˵�Id���Ӧ�Ľڵ���Ϣ

public:
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMS);
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	virtual BOOL AppendMenu(UINT nFlags=0,UINT_PTR nIDNewItem=0,LPCTSTR lpszNewItem=NULL,UINT hImg=NULL);
public:
	void SetItemSize(CSize sz)				{m_szItemSize = sz;				};	//���ò˵���Ŀ�ߴ�
	CSize GetItemSize()						{return m_szItemSize;			};

	void SetResourceType(LPCTSTR pa)		{m_sResourceType = pa;			};	//����ͼ����Դ���� ��BMP ֧���Զ�����Դ���� ��PNG,JPG
	LPCTSTR GetResourceType()				{return m_sResourceType;		};

	void SetSelectItemColor(COLORREF cr)	{m_crSelectItemCol = cr;		};	//���ò˵���Ŀ���ͣ����ɫ
	COLORREF GetSelectItemColor()			{return m_crSelectItemCol;		};

	void SetNormalItemColor(COLORREF cr)	{m_crNormalItemCol = cr;		};	//���ò˵���Ŀƽʱ����ɫ
	COLORREF GetNormalItemColor()			{return m_crNormalItemCol;		};

	void SetSelectTextColor(COLORREF cr)	{m_crSelectTextCol = cr;		};	//���ò˵��������ͣ����ɫ
	COLORREF GetSelectTextColor()			{return m_crSelectTextCol;		};

	void SetNomalTextColor(COLORREF cr)		{m_crNormalTextCol = cr;		};	//���ò˵�����ƽʱ��ɫ
	COLORREF GetNomalTextColor()			{return m_crNormalTextCol;		};

	void SetSelectImgBkColor(COLORREF cr)	{m_crSelectImgBkCol = cr;		};	//�������ͣ��ͼƬ������ɫ
	COLORREF GetSelectImgBkColor()			{return m_crSelectImgBkCol;		};

	void SetNormalImgBkColor(COLORREF cr)	{m_crNormalImgBkCol = cr;		};	//����ƽʱͼƬ������ɫ
	COLORREF GetNormalImgBkColor()			{return m_crNormalImgBkCol;		};

	void SetCheckItemColor(COLORREF cr)		{m_crCheckItemCol = cr;			};	//����ƽʱͼƬ������ɫ
	COLORREF GetCheckItemColor()			{return m_crCheckItemCol;		};

	void SetTextSize(int sz)				{m_nTextSize = sz;				};	//�������ִ�С
	int GetTextSize()						{return m_nTextSize;			};

	void SetTextType(LPCTSTR pa)			{m_sTextName = pa;				};	//��������
	LPCTSTR GetTextType()					{return m_sTextName;			};

	void SetNoBorder(BOOL bBor=TRUE);

protected:
	CSize    m_szItemSize;	
	LPCTSTR  m_sResourceType;
	int      m_nTextSize;
	LPCTSTR  m_sTextName;

	COLORREF m_crSelectItemCol;
	COLORREF m_crNormalItemCol;

	COLORREF m_crSelectTextCol;
	COLORREF m_crNormalTextCol;

	COLORREF m_crSelectImgBkCol;
	COLORREF m_crNormalImgBkCol;

	COLORREF m_crCheckItemCol;

	static CImage m_Image;
	void loadimage(CDC *pDC,CRect rect,LPCTSTR filePath,UINT nResID);
};


