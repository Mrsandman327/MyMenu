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
	CMap<WORD,WORD,SItem,SItem> m_map;//菜单Id与对应的节点信息

public:
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMS);
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	virtual BOOL AppendMenu(UINT nFlags=0,UINT_PTR nIDNewItem=0,LPCTSTR lpszNewItem=NULL,UINT hImg=NULL);
public:
	void SetItemSize(CSize sz)				{m_szItemSize = sz;				};	//设置菜单项目尺寸
	CSize GetItemSize()						{return m_szItemSize;			};

	void SetResourceType(LPCTSTR pa)		{m_sResourceType = pa;			};	//设置图像资源类型 如BMP 支持自定义资源类型 如PNG,JPG
	LPCTSTR GetResourceType()				{return m_sResourceType;		};

	void SetSelectItemColor(COLORREF cr)	{m_crSelectItemCol = cr;		};	//设置菜单项目鼠标停留颜色
	COLORREF GetSelectItemColor()			{return m_crSelectItemCol;		};

	void SetNormalItemColor(COLORREF cr)	{m_crNormalItemCol = cr;		};	//设置菜单项目平时的颜色
	COLORREF GetNormalItemColor()			{return m_crNormalItemCol;		};

	void SetSelectTextColor(COLORREF cr)	{m_crSelectTextCol = cr;		};	//设置菜单文字鼠标停留颜色
	COLORREF GetSelectTextColor()			{return m_crSelectTextCol;		};

	void SetNomalTextColor(COLORREF cr)		{m_crNormalTextCol = cr;		};	//设置菜单文字平时颜色
	COLORREF GetNomalTextColor()			{return m_crNormalTextCol;		};

	void SetSelectImgBkColor(COLORREF cr)	{m_crSelectImgBkCol = cr;		};	//设置鼠标停留图片背景颜色
	COLORREF GetSelectImgBkColor()			{return m_crSelectImgBkCol;		};

	void SetNormalImgBkColor(COLORREF cr)	{m_crNormalImgBkCol = cr;		};	//设置平时图片背景颜色
	COLORREF GetNormalImgBkColor()			{return m_crNormalImgBkCol;		};

	void SetCheckItemColor(COLORREF cr)		{m_crCheckItemCol = cr;			};	//设置平时图片背景颜色
	COLORREF GetCheckItemColor()			{return m_crCheckItemCol;		};

	void SetTextSize(int sz)				{m_nTextSize = sz;				};	//设置文字大小
	int GetTextSize()						{return m_nTextSize;			};

	void SetTextType(LPCTSTR pa)			{m_sTextName = pa;				};	//设置字体
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


