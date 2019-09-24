LPPOINT lpoint = new tagPOINT;
::GetCursorPos(lpoint);//得到当前鼠标位置
//先创建一个子菜单，在添加在父菜单中
CMyMenu SnbMenu;
SnbMenu.SetItemSize(CSize(95,26));					//设置菜单项目尺寸
SnbMenu.SetSelectItemColor(RGB(40,216,107));		//设置菜单项目鼠标停留颜色
SnbMenu.SetNormalItemColor(RGB(255,255,255));		//设置菜单项目平时的颜色
SnbMenu.SetNomalTextColor(RGB(53,53,53));			//设置菜单文字颜色
SnbMenu.SetSelectTextColor(RGB(255,255,255));		//设置菜单鼠标停留文字颜色
SnbMenu.SetSelectImgBkColor(RGB(40,216,107));       //设置菜单鼠标停留图像背景
SnbMenu.SetNormalImgBkColor(RGB(255,255,255));      //设置菜单图像背景
SnbMenu.SetCheckItemColor(RGB(128,128,255));        //设置选中项目背景  
SnbMenu.SetResourceType(_T("PNG"));					//设置图像资源类型 如BMP 支持自定义资源类型 如PNG,JPG
SnbMenu.SetTextType(_T("雅黑"));                    //设置字体
SnbMenu.SetTextSize(14);                            //设置文字大小
SnbMenu.CreatePopupMenu();
SnbMenu.SetNoBorder(TRUE);
SnbMenu.AppendMenu(MFT_STRING,		IDR_WINSHOW,	_T("Not Hidden"));
SnbMenu.AppendMenu(MFT_STRING,		IDR_WINHIDE,	_T("Auto Hide"));
if (m_winHide)
{
	SnbMenu.CheckMenuItem(0,MF_BYPOSITION|MF_UNCHECKED);
	SnbMenu.CheckMenuItem(1,MF_BYPOSITION|MF_CHECKED);
}
else
{
	SnbMenu.CheckMenuItem(0,MF_BYPOSITION|MF_CHECKED);
	SnbMenu.CheckMenuItem(1,MF_BYPOSITION|MF_UNCHECKED);
}

CMyMenu menu;
menu.SetItemSize(CSize(100,26));					//设置菜单项目尺寸
menu.SetSelectItemColor(RGB(40,216,107));			//设置菜单项目鼠标停留颜色
menu.SetNormalItemColor(RGB(255,255,255));			//设置菜单项目平时的颜色
menu.SetNomalTextColor(RGB(53,53,53));				//设置菜单文字颜色
menu.SetSelectTextColor(RGB(255,255,255));			//设置菜单鼠标停留文字颜色
menu.SetSelectImgBkColor(RGB(40,216,107));			//设置菜单鼠标停留图像背景
menu.SetNormalImgBkColor(RGB(255,255,255));			//设置菜单图像背景
menu.SetResourceType(_T("PNG"));					//设置图像资源类型 如BMP 支持自定义资源类型 如PNG,JPG
menu.SetTextType(_T("雅黑"));						//设置字体
menu.SetTextSize(14);								//设置文字大小
menu.CreatePopupMenu();
menu.SetNoBorder(TRUE);
menu.AppendMenu(MFT_STRING,				IDR_SHOW,					_T("Open"),			IDB_PNG2);
menu.AppendMenu(MFT_STRING|MF_POPUP,	(UINT_PTR)SnbMenu.m_hMenu,	_T("Window"),		IDB_PNG7);//添加二级菜单的方法
menu.AppendMenu(MFT_STRING,				IDR_RECOM,					_T("Reconnect"),	IDB_PNG3);
menu.AppendMenu(MFT_STRING,				IDR_DISCON,					_T("Disconnect"),	IDB_PNG4);
menu.AppendMenu(MFT_STRING,				IDR_ABOUT,					_T("About"),		IDB_PNG5);
menu.AppendMenu(MFT_STRING,				IDR_EXIT,					_T("Exit"),			IDB_PNG6);

SetForegroundWindow();
int xx=menu.TrackPopupMenu(TPM_LEFTALIGN|TPM_TOPALIGN|TPM_RETURNCMD,lpoint->x,lpoint->y,this);//显示菜单并获取选项ID

switch (xx)
{
case IDR_SHOW:
	break;
case IDR_RECOM:
	break;
case IDR_DISCON:
	break;
case IDR_EXIT:
	break;
case IDR_ABOUT:
	break;
case IDR_WINSHOW:

	break;
case IDR_WINHIDE:

	break;
}

HMENU hmenu = menu.Detach();
menu.DestroyMenu();
SnbMenu.Detach();
SnbMenu.DestroyMenu();

delete lpoint;