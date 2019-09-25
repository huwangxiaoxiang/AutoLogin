#include "stdafx.h"
#include "PageManager.h"
std::vector<Page> PageManager::pages = std::vector<Page>();

void PageManager::Instance()
{
	PageManager::pages.clear();

	Page home = Page(1, L"��ҳ");
	home.addKeyPoint(KeyPoint(281, 61, 1059906, BASEP_LEFT_TOP));
	home.addKeyPoint(KeyPoint(-468, -71, 1066495, BASEP_CENTER_BOTTOM));
	home.addKeyPoint(KeyPoint(468, -71, 1262847, BASEP_CENTER_BOTTOM));
	home.addKeyPoint(KeyPoint(-263, 13, 16777215, BASEP_RIGHT_TOP));
	pages.push_back(home);

	Page searchExperience = Page(2, L"������ȡ�з�����");
	searchExperience.addKeyPoint(KeyPoint(-12, -159, 2171347, BASEP_CENTER_BOTTOM));
	searchExperience.addKeyPoint(KeyPoint(281, 61, 1059906, BASEP_LEFT_TOP));
	searchExperience.addKeyPoint(KeyPoint(-468, -71, 1066495, BASEP_CENTER_BOTTOM));
	searchExperience.addKeyPoint(KeyPoint(468, -71, 1262847, BASEP_CENTER_BOTTOM));
	pages.push_back(searchExperience);

	Page updateInfo = Page(3, L"���¹������");
	updateInfo.addKeyPoint(KeyPoint(458, -295, 16777215, BASEP_CENTER));
	updateInfo.addKeyPoint(KeyPoint(431, -175, 731562, BASEP_CENTER));
	updateInfo.addKeyPoint(KeyPoint(431, 270, 731562, BASEP_CENTER));
	updateInfo.setClose(458, -295, BASEP_CENTER);
	pages.push_back(updateInfo);

	Page obtainskill = Page(4, L"������ѳ�ȡ���ܣ���ҳ��");
	obtainskill.addKeyPoint(KeyPoint(-220, -157, 2171347, BASEP_CENTER_BOTTOM));
	obtainskill.addKeyPoint(KeyPoint(281, 61, 1059906, BASEP_LEFT_TOP));
	obtainskill.addKeyPoint(KeyPoint(-468, -71, 1066495, BASEP_CENTER_BOTTOM));
	obtainskill.addKeyPoint(KeyPoint(468, -71, 1262847, BASEP_CENTER_BOTTOM));
	pages.push_back(obtainskill);

	Page obtaincond = Page(5, L"������ѳ�ȡָ�ӹ٣���ҳ��");
	obtaincond.addKeyPoint(KeyPoint(92, -158, 2171347, BASEP_CENTER_BOTTOM));
	obtaincond.addKeyPoint(KeyPoint(281, 61, 1059906, BASEP_LEFT_TOP));
	obtaincond.addKeyPoint(KeyPoint(-468, -71, 1066495, BASEP_CENTER_BOTTOM));
	obtaincond.addKeyPoint(KeyPoint(468, -71, 1262847, BASEP_CENTER_BOTTOM));
	pages.push_back(obtaincond);

	Page onlinegift = Page(6, L"������ȡ�������");
	onlinegift.addKeyPoint(KeyPoint(-59, 138, 16775151, BASEP_RIGHT_TOP));
	onlinegift.addKeyPoint(KeyPoint(281, 61, 1059906, BASEP_LEFT_TOP));
	onlinegift.addKeyPoint(KeyPoint(-468, -71, 1066495, BASEP_CENTER_BOTTOM));
	onlinegift.addKeyPoint(KeyPoint(468, -71, 1262847, BASEP_CENTER_BOTTOM));
	pages.push_back(onlinegift);

	Page remakepage = Page(7, L"��װ����");
	remakepage.addKeyPoint(KeyPoint(486, -298, 16777215, BASEP_CENTER));
	remakepage.addKeyPoint(KeyPoint(-450, 229, 1262847, BASEP_CENTER));
	remakepage.addKeyPoint(KeyPoint(450, 229, 1262847, BASEP_CENTER));
	remakepage.addKeyPoint(KeyPoint(346, -37, 4342338, BASEP_CENTER));
	remakepage.setClose(486, -298, BASEP_CENTER);
	pages.push_back(remakepage);

	Page skillpage = Page(8, L"��ȡ���ܽ���");
	skillpage.addKeyPoint(KeyPoint(486, -298, 16777215, BASEP_CENTER));
	skillpage.addKeyPoint(KeyPoint(-147, -250, 1778517, BASEP_CENTER));
	skillpage.addKeyPoint(KeyPoint(227, -77, 4346268, BASEP_CENTER));
	skillpage.addKeyPoint(KeyPoint(-93, 135, 4342338, BASEP_CENTER));
	skillpage.setClose(486, -298, BASEP_CENTER);
	pages.push_back(skillpage);

	Page guide = Page(9, L"���ֽ̳�ѡ������");
	guide.addKeyPoint(KeyPoint(489, -218, 16777215, BASEP_CENTER));
	guide.addKeyPoint(KeyPoint(60, 124, 1781988, BASEP_CENTER));
	guide.setClose(489, -218, BASEP_CENTER);
	pages.push_back(guide);

}

std::wstring PageManager::ShowPageList()
{
	std::wostringstream str;
	for (auto i = pages.cbegin(); i != pages.cend(); i++) {
		Page temp = *i;
		str << temp.getIndex() << " ";
		str <<temp.getPageName() << "\n";
	}
	//AfxMessageBox(str.str().c_str(), 0, 0);
	return str.str();
}

Page PageManager::isThisPage(int index,HWND process)
{
	if (process != NULL&&index!=-1) {
		for (auto i = pages.cbegin(); i != pages.cend(); i++) {
			Page ind = *i;
			if (ind.getIndex() == index && ind.isThisPage(process)) {
				return ind;
			}
		}
	}
	return Page(-1, L"��ЧPage");
}

Page PageManager::getPage(int pageIndex)
{
	for (auto i = pages.cbegin(); i != pages.cend(); i++) {
		Page ind = *i;
		if (ind.getIndex() == pageIndex) {
			return ind;
		}
	}
	return Page(-1, L"��ЧPage");
}
