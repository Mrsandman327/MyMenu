// MyMenu.cpp : 实现文件
//

#include "stdafx.h"
#include "MyMenu.h"

CImage CMyMenu::m_Image;
CMyMenu::CMyMenu()
{
	m_szItemSize.cx			=	95;
	m_szItemSize.cy			=	26;

	m_nTextSize				=	13;

	m_sResourceType			=	_T("PNG");
	m_sTextName				=	_T("宋体");

	m_crNormalItemCol		=	RGB(255,255,255);
	m_crSelectItemCol		=	RGB(226,226,226);

	m_crNormalTextCol		=	RGB(53,53,53);
	m_crSelectTextCol		=	RGB(0,0,0);

	m_crSelectImgBkCol		=	RGB(226,226,226);
	m_crNormalImgBkCol		=	RGB(255,255,255);

	m_crCheckItemCol		=	RGB(128,128,255); 
}

CMyMenu::~CMyMenu()
{
}

void CMyMenu::SetNoBorder(BOOL bBor)
{
	if (bBor)
	{
		MENUINFO menuinfo;
		menuinfo.cbSize = sizeof(MENUINFO);
		menuinfo.fMask = MIM_APPLYTOSUBMENUS | MIM_BACKGROUND;  //选择设置的类型
		CBrush br;br.CreateSolidBrush(GetNormalItemColor());
		menuinfo.hbrBack =(HBRUSH)&br;
		SetMenuInfo(&menuinfo);
		br.DeleteObject();
	}
}

void CMyMenu::MeasureItem(LPMEASUREITEMSTRUCT lpMS)
{
	lpMS->itemWidth = m_szItemSize.cx;//菜单项的宽度

	lpMS->itemHeight = m_map[lpMS->itemID].nHeight;//每个菜单项的高度
}

void CMyMenu::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{

	CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);

	CRect rect = lpDrawItemStruct->rcItem;

	CString strText;
	SItem &sItem = m_map[lpDrawItemStruct->itemID];

	if(lpDrawItemStruct->itemID) strText = sItem.szText;

	CRect ImgRc=rect;
	ImgRc.right=rect.left+rect.Height();
	CRect TextRc=rect;
	TextRc.left+=rect.Height();
	if((lpDrawItemStruct->itemState & ODS_SELECTED)&&(lpDrawItemStruct->itemAction & ODA_SELECT))
	{
		pDC->FillSolidRect(&TextRc,m_crSelectItemCol/*::GetSysColor(COLOR_MENU)*/);
		pDC->FillSolidRect(&ImgRc,m_crSelectImgBkCol/*::GetSysColor(COLOR_MENU)*/);
		pDC->SetTextColor(m_crSelectTextCol);	

		//CPen pen(PS_SOLID,1,GetSysColor(COLOR_HIGHLIGHT));
		////rect.DeflateRect(1,1);
		//CBrush br(RGB(182,189,210));
		//pDC->SelectObject(&pen);
		//pDC->SelectObject(br);
		//pDC->Rectangle(rect);

	}
	else if(lpDrawItemStruct->itemState & ODS_CHECKED)
	{
		pDC->FillSolidRect(&TextRc,m_crCheckItemCol/*::GetSysColor(COLOR_MENU)*/);
		pDC->FillSolidRect(&ImgRc,m_crCheckItemCol/*::GetSysColor(COLOR_MENU)*/);
		pDC->SetTextColor(m_crSelectTextCol);	
	}
	else//非选中状态:普通背景填充
	{
		pDC->FillSolidRect(&TextRc,m_crNormalItemCol/*GetSysColor(COLOR_MENU)*/);
		pDC->FillSolidRect(&ImgRc,m_crNormalImgBkCol/*::GetSysColor(COLOR_MENU)*/);
		pDC->SetTextColor(m_crNormalTextCol);

		if (rect.Height() == 3)//如果是分隔条菜单:画两条线
		{
			CPen pen1(PS_SOLID,1,GetSysColor(COLOR_BTNSHADOW));
			CPen *Oldpen1=pDC->SelectObject(&pen1);
			pDC->MoveTo(rect.left+2,rect.top+1);
			pDC->LineTo(rect.right-2,rect.top+1);
			pDC->SelectObject(Oldpen1);
			pen1.DeleteObject();
			Oldpen1=NULL;

			CPen pen2(PS_SOLID,1,GetSysColor(COLOR_HOTLIGHT));
			CPen *Oldpen2=pDC->SelectObject(&pen2);
			pDC->MoveTo(rect.left+2,rect.top+2);
			pDC->LineTo(rect.right-2,rect.top+2);
			pDC->SelectObject(Oldpen2);
			pen2.DeleteObject();
			Oldpen2=NULL;

			return;
		}
		rect.DeflateRect(1,1);

	}

	if(sItem.hImg)
	{
		loadimage(pDC,ImgRc,m_sResourceType,sItem.hImg);
	}
	CFont TextFont;
	TextFont.CreateFont(
		m_nTextSize,               // 字体的高度           
		0,                         // 字体的宽度
		0,                         // 字体显示的角度
		0,                         // 字体的角度
		FW_NORMAL,                 // 字体的磅数
		FALSE,                     // 斜体字体
		FALSE,                     // 带下划线的字体
		0,                         // 带删除线的字体
		ANSI_CHARSET,              // 所需的字符集
		OUT_DEFAULT_PRECIS,        // 输出的精度
		CLIP_DEFAULT_PRECIS,       // 裁减的精度
		DEFAULT_QUALITY,           // 逻辑字体与输出设备的实际字体之间的精度
		DEFAULT_PITCH | FF_SWISS,  // 字体间距和字体集
		m_sTextName);              // 字体名称
	CFont* pOldFont = NULL;           
	pOldFont = pDC->SelectObject(&TextFont);

	
	pDC->SetBkMode(TRANSPARENT);
	if(sItem.hImg)
	{
		rect.left+=ImgRc.Width()+10;
		pDC->DrawText(strText,rect,DT_LEFT|DT_VCENTER|DT_SINGLELINE);
	}
	else
	{
		pDC->DrawText(strText,rect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	}

	pDC->SelectObject(pOldFont);
	TextFont.DeleteObject();
	pOldFont=NULL;
}


BOOL CMyMenu::AppendMenu(UINT nFlags,UINT_PTR nIDNewItem,LPCTSTR lpszNewItem,UINT hImg)
{
	//将菜单的文字和图标信息按照ID进行登记，以便自绘时使用
	SItem sItem = {hImg};
	if(nFlags & MF_SEPARATOR) 
	{
		sItem.nHeight = 3;
	}
	else
	{
		sItem.nHeight = m_szItemSize.cy;
#ifdef _UNICODE
		if(lpszNewItem)WideCharToMultiByte(CP_ACP, 0, lpszNewItem, -1, sItem.szText, 100, NULL, NULL);
#else
		if(lpszNewItem) strcpy(sItem.szText,lpszNewItem);
#endif
	}
	//根据ID添加到map中
	m_map[nIDNewItem] = sItem;
	//每个插入的菜单项都自动添加自绘属性
	return CMenu::AppendMenu(nFlags|MF_OWNERDRAW,nIDNewItem,lpszNewItem);

}


void CMyMenu::loadimage(CDC *pDC,CRect rect,LPCTSTR lpType,UINT nResID)
{
	if (!m_Image.IsNull())
	{
		m_Image.Destroy();
	}
	CComPtr<IStream> stream;
	stream = NULL;
	// 查找资源
	HRSRC hRsrc = ::FindResource(AfxGetResourceHandle(), MAKEINTRESOURCE(nResID), lpType);
	if (hRsrc == NULL) return;

	// 加载资源
	HGLOBAL hImgData = ::LoadResource(AfxGetResourceHandle(), hRsrc);
	if (hImgData == NULL)
	{
		::FreeResource(hImgData);
		return;
	}

	// 锁定内存中的指定资源
	LPVOID lpVoid    = ::LockResource(hImgData);

	//LPSTREAM pStream = NULL;
	DWORD dwSize    = ::SizeofResource(AfxGetResourceHandle(), hRsrc);
	HGLOBAL hNew    = ::GlobalAlloc(GHND, dwSize);
	LPVOID lpByte    = (LPBYTE)::GlobalLock(hNew);
	::memcpy(lpByte, lpVoid, dwSize);

	// 解除内存中的指定资源
	::GlobalUnlock(hNew);

	// 从指定内存创建流对象
	HRESULT ht = ::CreateStreamOnHGlobal(hNew, TRUE, &stream);
	if ( ht != S_OK )
	{
		GlobalFree(hNew);
	}
	else
	{
		// 加载图片
		HRESULT ret = m_Image.Load(stream);
		if (S_OK==ret)
		{
			if (m_Image.GetBPP() == 32)
			{
				for (int i=0;i<m_Image.GetWidth();i++)
				{
					for (int j=0;j<m_Image.GetHeight();j++)
					{
						unsigned char* pucColor = reinterpret_cast<unsigned char *>(m_Image.GetPixelAddress(i , j)); 
						pucColor[0] = pucColor[0] * pucColor[3] / 255;   
						pucColor[1] = pucColor[1] * pucColor[3] / 255;   
						pucColor[2] = pucColor[2] * pucColor[3] / 255;   
					}
				}
			}

			if(rect.Width()>m_Image.GetWidth())
			{
				rect.DeflateRect((rect.Width()-m_Image.GetWidth())/2,0);
			}
			if(rect.Height()>m_Image.GetHeight())
			{
				rect.DeflateRect(0,(rect.Height()-m_Image.GetHeight())/2);
			}
			m_Image.Draw(pDC->m_hDC,rect);
		}

		GlobalFree(hNew);
	}
	
	// 释放资源
	::FreeResource(hImgData);
}



