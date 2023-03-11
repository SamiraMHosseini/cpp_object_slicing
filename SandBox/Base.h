#ifndef BASE_H
#define BASE_H
enum class ClassType
{
	DERIVED,
	BASE
};
struct Base
{
public:
	static Base* GetInstance(const ClassType& type);
	static Base& GetInstance2A(const ClassType& type);
	static Base& GetInstance2B(const ClassType& type);
	static Base& GetInstance2C(const ClassType& type);
	static Base& GetInstance3(const ClassType& type);
	static Base  GetInstance4(const ClassType& type);
	static std::unique_ptr<Base>& GetInstance5(const ClassType& type);
	virtual void Print() const;
	int i = 1;
	static Base instance;   //this is not a reference type to Base so it'll cause object slicing
	static Base* pInstance; //this is  a pointer type to Base so it'll NOT cause object slicing
	static std::unique_ptr<Base> puInstance;
	//Rule of 0
    Base() = default;
	Base(const Base& base) = default;
	Base& operator=(const Base& base) = default;
	Base(Base&& base) = default;
	Base& operator=(Base&& base) = default;
	virtual ~Base() = default;

};

#endif
