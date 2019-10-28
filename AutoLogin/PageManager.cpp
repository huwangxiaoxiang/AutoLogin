#include "stdafx.h"
#include "PageManager.h"
#include "SysGiftPage.h"
std::vector<Page*> PageManager::pages = std::vector<Page*>();

void PageManager::Instance()
{
	PageManager::pages.clear();

	Page* home = new Page(1, L"主页");
	home->addKeyPoint(KeyPoint(281, 61, 1059906, BASEP_LEFT_TOP));
	home->addKeyPoint(KeyPoint(-468, -71, 1066495, BASEP_CENTER_BOTTOM));
	home->addKeyPoint(KeyPoint(468, -71, 1262847, BASEP_CENTER_BOTTOM));
	home->addKeyPoint(KeyPoint(-263, 13, 16777215, BASEP_RIGHT_TOP));
	pages.push_back(home);

	Page* searchExperience = new Page(2, L"可以领取研发经验");
	searchExperience->addKeyPoint(KeyPoint(-12, -159, 2171347, BASEP_CENTER_BOTTOM));
	searchExperience->addKeyPoint(KeyPoint(281, 61, 1059906, BASEP_LEFT_TOP));
	searchExperience->addKeyPoint(KeyPoint(-468, -71, 1066495, BASEP_CENTER_BOTTOM));
	searchExperience->addKeyPoint(KeyPoint(468, -71, 1262847, BASEP_CENTER_BOTTOM));
	pages.push_back(searchExperience);

	Page* updateInfo = new Page(3, L"更新公告面板");
	updateInfo->addKeyPoint(KeyPoint(458, -295, 16777215, BASEP_CENTER));
	updateInfo->addKeyPoint(KeyPoint(358,-244,1052429, BASEP_CENTER));
	updateInfo->addKeyPoint(KeyPoint(-67,-298,8323071, BASEP_CENTER));
	updateInfo->setClose(458, -295, BASEP_CENTER);
	pages.push_back(updateInfo);

	Page* obtainskill = new Page(4, L"可以免费抽取技能（主页）");
	obtainskill->addKeyPoint(KeyPoint(-220, -157, 2171347, BASEP_CENTER_BOTTOM));
	obtainskill->addKeyPoint(KeyPoint(281, 61, 1059906, BASEP_LEFT_TOP));
	obtainskill->addKeyPoint(KeyPoint(-468, -71, 1066495, BASEP_CENTER_BOTTOM));
	obtainskill->addKeyPoint(KeyPoint(468, -71, 1262847, BASEP_CENTER_BOTTOM));
	pages.push_back(obtainskill);

	Page* obtaincond =new Page(5, L"可以免费抽取指挥官（主页）");
	obtaincond->addKeyPoint(KeyPoint(92, -158, 2171347, BASEP_CENTER_BOTTOM));
	obtaincond->addKeyPoint(KeyPoint(281, 61, 1059906, BASEP_LEFT_TOP));
	obtaincond->addKeyPoint(KeyPoint(-468, -71, 1066495, BASEP_CENTER_BOTTOM));
	obtaincond->addKeyPoint(KeyPoint(468, -71, 1262847, BASEP_CENTER_BOTTOM));
	pages.push_back(obtaincond);

	Page* onlinegift =new Page(6, L"可以领取在线礼包");
	onlinegift->addKeyPoint(KeyPoint(-59, 138, 16775151, BASEP_RIGHT_TOP));
	onlinegift->addKeyPoint(KeyPoint(281, 61, 1059906, BASEP_LEFT_TOP));
	onlinegift->addKeyPoint(KeyPoint(-468, -71, 1066495, BASEP_CENTER_BOTTOM));
	onlinegift->addKeyPoint(KeyPoint(468, -71, 1262847, BASEP_CENTER_BOTTOM));
	pages.push_back(onlinegift);

	Page* remakepage =new Page(7, L"改装界面");
	remakepage->addKeyPoint(KeyPoint(486, -298, 16777215, BASEP_CENTER));
	remakepage->addKeyPoint(KeyPoint(-450, 229, 1262847, BASEP_CENTER));
	remakepage->addKeyPoint(KeyPoint(450, 229, 1262847, BASEP_CENTER));
	remakepage->addKeyPoint(KeyPoint(346, -37, 4342338, BASEP_CENTER));
	remakepage->setClose(486, -298, BASEP_CENTER);
	pages.push_back(remakepage);

	Page* skillpage =new Page(8, L"抽取技能界面");
	skillpage->addKeyPoint(KeyPoint(486, -298, 16777215, BASEP_CENTER));
	skillpage->addKeyPoint(KeyPoint(-147, -250, 1778517, BASEP_CENTER));
	skillpage->addKeyPoint(KeyPoint(227, -77, 4346268, BASEP_CENTER));
	skillpage->addKeyPoint(KeyPoint(-93, 135, 4342338, BASEP_CENTER));
	skillpage->setClose(486, -298, BASEP_CENTER);
	pages.push_back(skillpage);

	Page* guide =new Page(9, L"新手教程选车界面");
	guide->addKeyPoint(KeyPoint(489, -218, 16777215, BASEP_CENTER));
	guide->addKeyPoint(KeyPoint(60, 124, 1781988, BASEP_CENTER));
	guide->setClose(489, -218, BASEP_CENTER);
	pages.push_back(guide);

	SysGiftPage* sysgift =new  SysGiftPage(10,L"领取系统礼包");
	sysgift->addKeyPoint(KeyPoint(416, 146, 16777215, BASEP_CENTER));
	sysgift->addKeyPoint(KeyPoint(478, -269, 16777215, BASEP_CENTER));
	sysgift->setClose(478, -269, BASEP_CENTER);
	pages.push_back(sysgift);

}

std::wstring PageManager::ShowPageList()
{
	std::wostringstream str;
	for (auto i = pages.cbegin(); i != pages.cend(); i++) {
		Page* temp = *i;
		str << temp->getIndex() << " ";
		str <<temp->getPageName() << "\n";
	}
	//AfxMessageBox(str.str().c_str(), 0, 0);
	return str.str();
}

Page* PageManager::isThisPage(int index,HWND process)
{
	if (process != NULL&&index!=-1) {
		for (auto i = pages.cbegin(); i != pages.cend(); i++) {
			Page* ind = *i;
			if (ind->getIndex() == index && ind->isThisPage(process)) {
				return ind;
			}
		}
	}
	return new Page(-1, L"无效Page");
}

Page* PageManager::getPage(int pageIndex)
{
	for (auto i = pages.cbegin(); i != pages.cend(); i++) {
		Page* ind = *i;
		if (ind->getIndex() == pageIndex) {
			return ind;
		}
	}
	return new Page(-1, L"无效Page");
}
