#pragma once
#include<afxtempl.h>
#include<algorithm>
struct SStud
{
	int nType;
	int nNumb;
	char sName[20];
	char sSex[4];
	SStud* InputInfo(const SStud& data);
};


struct SScie :public SStud
{
	float fMath;
	float fPhys;
	float fChem;
	float fBiol;
	SStud* Input(const SScie& data);
};

struct SArt :public SStud
{
	float fMath;
	float fEngl;
	float fGeog;
	float fHist;
	float fPoli;
	SStud* Input(const SArt& data);
};
class CStudent
{
private:
	CList<SStud*>m_list;
public:
	CStudent();
	~CStudent();
	int Main();
	int Menu();
	void Printone(const POSITION pos);
	void Input();
	void Add(int);
	void AddArt(int);
	void AddScie(int);
	void Browse();
	void Delete();
	void Modify();
	void Search();
	void SearchbyNumb(int numb,POSITION& pos);
	SStud** Sort(int n);
	void PrintAll(SStud**,int n);
	static bool SortbyName(SStud*,SStud*);
	static bool SortbyNumb(SStud*,SStud*);
	static bool SortbyMath(SScie*, SScie*);
	static bool SortbyPhys(SScie*, SScie*);
	static bool SortbyChem(SScie*, SScie*);
	static bool SortbyBiol(SScie*, SScie*);
	static bool SortbyEngl(SArt*, SArt*);
	static bool SortbyGeog(SArt*, SArt*);
	static bool SortbyHist(SArt*, SArt*);
	static bool SortbyPoli(SArt*, SArt*);
	void Save();
	void Load();
};

