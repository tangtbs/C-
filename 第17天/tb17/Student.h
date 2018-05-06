#pragma once
#include<afxtempl.h>
#include<algorithm>
struct SStud
{
	int nType;
	char sName[20];
	int nNumb;
	char sSex[4];
	virtual ~SStud();
	virtual void Input(const SStud&) = 0;
	virtual void Modify()=0;
	virtual void Print()=0;
	virtual int Type() = 0;
	virtual bool SortbyNumb(SStud*) = 0;
	virtual bool SortbyName(SStud*) = 0;
	virtual bool SortbyMath(SStud*) = 0;
	virtual bool SortbyEngl(SStud*) = 0;
	virtual bool SortbyHist(SStud*) = 0;
	virtual bool SortbyGeog(SStud*) = 0;
	virtual bool SortbyPoli(SStud*) = 0;
	virtual bool SortbyChem(SStud*) = 0;
	virtual bool SortbyPhys(SStud*) = 0;
	virtual bool SortbyBiol(SStud*) = 0;
	virtual void Save(FILE*) = 0;
};


struct SScie :public SStud
{
	float fMath;
	float fPhys;
	float fChem;
	float fBiol;
	~SScie()
	{
	}
	void Input(const SStud&);
	void Modify();
	void Print();
	virtual int Type()
	{
		return 1;
	}
	virtual bool SortbyNumb(SStud*);
	virtual bool SortbyName(SStud*);
	virtual bool SortbyMath(SStud*);
	virtual bool SortbyChem(SStud*);
	virtual bool SortbyPhys(SStud*);
	virtual bool SortbyBiol(SStud*);
	virtual bool SortbyEngl(SStud*) { return 1 != 0; };
	virtual bool SortbyHist(SStud*) { return 1 != 0; };
	virtual bool SortbyGeog(SStud*) { return 1 != 0; };
	virtual bool SortbyPoli(SStud*) { return 1 != 0; };
	virtual void Save(FILE*fp)
	{
		fwrite(&this->nType, sizeof(SScie) - sizeof(void*), 1, fp);
	}


};

struct SArt :public SStud
{
	float fMath;
	float fEngl;
	float fGeog;
	float fHist;
	float fPoli;
	~SArt()
	{
	}
	void Input(const SStud& );
	void Delete();
	void Modify();
	void Print();
	virtual int Type()
	{
		return 0;
	}
	virtual bool SortbyNumb(SStud*);
	virtual bool SortbyName(SStud*);
	virtual bool SortbyMath(SStud*);
	virtual bool SortbyEngl(SStud*);
	virtual bool SortbyHist(SStud*);
	virtual bool SortbyGeog(SStud*);
	virtual bool SortbyPoli(SStud*);
	virtual bool SortbyChem(SStud*) { return 1 != 0; };
	virtual bool SortbyPhys(SStud*) { return 1 != 0; };
	virtual bool SortbyBiol(SStud*) { return 1 != 0; };
	virtual void Save(FILE*fp)
	{
		fwrite(&this->nType, sizeof(SArt) - sizeof(void*), 1, fp);
	}
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
	void Printone(SStud*);
	void Input();
	void Add(int);
	void AddArt(int);
	void AddScie(int);
	void Browse();
	void Delete();
	void Modify();
	void Search();
	void SearchbyNumb(int numb, POSITION& pos);
	SStud** Sort(int n);
	void PrintAll(SStud**, int n);
	static bool SortbyName(SStud*, SStud*);
	static bool SortbyNumb(SStud*, SStud*);
	static bool SortbyMath(SStud*, SStud*);
	static bool SortbyPhys(SStud*, SStud*);
	static bool SortbyChem(SStud*, SStud*);
	static bool SortbyBiol(SStud*, SStud*);
	static bool SortbyEngl(SStud*, SStud*);
	static bool SortbyGeog(SStud*, SStud*);
	static bool SortbyHist(SStud*, SStud*);
	static bool SortbyPoli(SStud*, SStud*);
	void Save();
	void Load();
};

