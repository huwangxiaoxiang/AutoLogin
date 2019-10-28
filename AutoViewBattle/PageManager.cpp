#include "pch.h"
#include "PageManager.h"

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

	Page* L1 = new Page(2, L"列表1");
	L1->addKeyPoint(KeyPoint(333, -130,14262052, BASEP_CENTER));
	pages.push_back(L1);

	Page* L2 = new Page(3, L"列表2");
	L2->addKeyPoint(KeyPoint(333, -70, 14262052, BASEP_CENTER));
	pages.push_back(L2);

	Page* L3 = new Page(4, L"列表3");
	L3->addKeyPoint(KeyPoint(333, -8, 14262052, BASEP_CENTER));
	pages.push_back(L3);

	Page* L4 = new Page(5, L"列表4");
	L4->addKeyPoint(KeyPoint(333, 52, 14262052, BASEP_CENTER));
	pages.push_back(L4);


	Page* L5 = new Page(6, L"列表5");
	L5->addKeyPoint(KeyPoint(333, 114, 14262052, BASEP_CENTER));
	pages.push_back(L5);

	Page* L6 = new Page(7, L"列表6");
	L6->addKeyPoint(KeyPoint(333, 174, 14262052, BASEP_CENTER));
	pages.push_back(L6);
	


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
