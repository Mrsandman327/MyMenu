LPPOINT lpoint = new tagPOINT;
::GetCursorPos(lpoint);//�õ���ǰ���λ��
//�ȴ���һ���Ӳ˵���������ڸ��˵���
CMyMenu SnbMenu;
SnbMenu.SetItemSize(CSize(95,26));					//���ò˵���Ŀ�ߴ�
SnbMenu.SetSelectItemColor(RGB(40,216,107));		//���ò˵���Ŀ���ͣ����ɫ
SnbMenu.SetNormalItemColor(RGB(255,255,255));		//���ò˵���Ŀƽʱ����ɫ
SnbMenu.SetNomalTextColor(RGB(53,53,53));			//���ò˵�������ɫ
SnbMenu.SetSelectTextColor(RGB(255,255,255));		//���ò˵����ͣ��������ɫ
SnbMenu.SetSelectImgBkColor(RGB(40,216,107));       //���ò˵����ͣ��ͼ�񱳾�
SnbMenu.SetNormalImgBkColor(RGB(255,255,255));      //���ò˵�ͼ�񱳾�
SnbMenu.SetCheckItemColor(RGB(128,128,255));        //����ѡ����Ŀ����  
SnbMenu.SetResourceType(_T("PNG"));					//����ͼ����Դ���� ��BMP ֧���Զ�����Դ���� ��PNG,JPG
SnbMenu.SetTextType(_T("�ź�"));                    //��������
SnbMenu.SetTextSize(14);                            //�������ִ�С
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
menu.SetItemSize(CSize(100,26));					//���ò˵���Ŀ�ߴ�
menu.SetSelectItemColor(RGB(40,216,107));			//���ò˵���Ŀ���ͣ����ɫ
menu.SetNormalItemColor(RGB(255,255,255));			//���ò˵���Ŀƽʱ����ɫ
menu.SetNomalTextColor(RGB(53,53,53));				//���ò˵�������ɫ
menu.SetSelectTextColor(RGB(255,255,255));			//���ò˵����ͣ��������ɫ
menu.SetSelectImgBkColor(RGB(40,216,107));			//���ò˵����ͣ��ͼ�񱳾�
menu.SetNormalImgBkColor(RGB(255,255,255));			//���ò˵�ͼ�񱳾�
menu.SetResourceType(_T("PNG"));					//����ͼ����Դ���� ��BMP ֧���Զ�����Դ���� ��PNG,JPG
menu.SetTextType(_T("�ź�"));						//��������
menu.SetTextSize(14);								//�������ִ�С
menu.CreatePopupMenu();
menu.SetNoBorder(TRUE);
menu.AppendMenu(MFT_STRING,				IDR_SHOW,					_T("Open"),			IDB_PNG2);
menu.AppendMenu(MFT_STRING|MF_POPUP,	(UINT_PTR)SnbMenu.m_hMenu,	_T("Window"),		IDB_PNG7);//��Ӷ����˵��ķ���
menu.AppendMenu(MFT_STRING,				IDR_RECOM,					_T("Reconnect"),	IDB_PNG3);
menu.AppendMenu(MFT_STRING,				IDR_DISCON,					_T("Disconnect"),	IDB_PNG4);
menu.AppendMenu(MFT_STRING,				IDR_ABOUT,					_T("About"),		IDB_PNG5);
menu.AppendMenu(MFT_STRING,				IDR_EXIT,					_T("Exit"),			IDB_PNG6);

SetForegroundWindow();
int xx=menu.TrackPopupMenu(TPM_LEFTALIGN|TPM_TOPALIGN|TPM_RETURNCMD,lpoint->x,lpoint->y,this);//��ʾ�˵�����ȡѡ��ID

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