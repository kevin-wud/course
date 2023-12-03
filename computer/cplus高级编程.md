# C++高级编程

### 灵活而奇特的C++

#### 引用

##### 引用变量

引用变量在创建时必须初始化，通常会在声明引用时对其进行初始化，但是对于包含类而言，需要在构造函数初始化器中初始化引用数据成员。

不能创建对未命名值的引用，除非这个引用是一个const值。

```C++
int& unnameRef = 5; // does not complie
const int$ unnameRef = 5; // works as expected
```

###### 1、修改引用

引用总是引用初始化的那个变量；引用一旦创建，就无法修改。如果在声明引用时用一个变量“赋值”，那么这个引用就指向这个变量。然而，如果在此后使用变量对引用赋值，被引用变量的值就变味被赋值变量的值，引用不会更新为指向这个变量。

```C++
int x = 3, y = 4;
int$ xref = x;
xref = y; // change value of x to 4. does not make xref refer to y
```

###### 2、指向指针的引用和指向引用的指针

可创建任何类型的引用，包括指针类型。

```C++
int* intP;
int*& ptrRef = intP;
ptrRef = new int;
*ptrRef = 5;
// ptrRef是一个指向intP的引用，intP是一个指向int值的指针。修改ptrRef会更改intP。
```

```C++
int x = 3;
int& xRef = x;
int* xPtr = &xRef;
*xPtr = 100;
```

无法声明引用的引用或者指向引用的指针（int&& 或 int&*）。

##### 使用引用还是指针

- 引用可使程序整洁并易于理解。
- 引用比指针安全：不可能存在无效引用，也不需要显式地解除引用。

大多数情况下，应该使用引用而不是指针。对象的引用可像指向对象的指针那样支持多态。但也有一些情况要求使用指针：

- 更改指向的位置，因为无法改变引用所指向的变量。
- 可选参数，即指针参数可以定义为带默认值nullptr的可选参数，而引用参数不能这样定义。
- 要在容器中存储多态类型。

判断使用指针还是引用作为参数和返回类型：考虑谁拥有内存。如果接收变量的代码负责释放相关对象的内存，那么必须使用指向对象的指针，最好是智能指针，这是传递拥有权的推荐方式。如果接收变量的代码不需要释放内存，那么应该使用引用。

```C++
// C 
void separateOddsAndEvens(const int arr[], size_t size, int** odds,
    size_t* numOdds, int** evens, size_t* numEvens)
{
    //count the number of odds and evens
    *numOdds = *numEvens = 0;
    for(size_t i = 0; i < size; i++){
        if(arr[i]%2 == 1){
            ++(*numOdds);
        }else{
            ++(*numEvens);
        }
    }

    // Allocate two new arrays of the appropriate size
    *odds = new int[*numOdds];
    *evens = new int[*numEvens];

    // copy the odds and evens to the new arrays
    size_t oddsPos = 0, evensPos = 0;
    for(size_t i = 0; i < size; i++){
        if(arr[i]%2 == 1){
            (*odds)[oddsPos++] = arr[i];
        }else{
            (*evens)[evensPos++] = arr[i];
        }
    }
}

int unSplit[] = {1,2,3,4,5,6,7,8};
int* oddsNum = nullptr;
int* evensNum = nullptr;
size_t numOdds = 0, numEvens = 0;

separateOddsAndEvens(unSplit, std::size(unSplit), &oddsNum,
    &numOdds, &evensNum, &numEvens);

delete[] oddsNum; oddsNum = nullptr;
delete[] evensNum; evensNum = nullptr;
```



### 关键字

- explicit
  
  *explicit*关键字只在定义内使用，只适用于只有一个参数的构造函数。

### 嵌套类

类定义不仅可以包含成员函数和数据成员，还可以编写嵌套类和嵌套结构、声明*typedef*或者创建枚举类型。类中声明的一切内容都具有类作用域。

```C++
class Spreadsheet
{
    public:
        class Cell
        {
            public:
                Cell() = default;
        };
        Spreadsheet() = default;
}
```

普通访问控制也适用于嵌套类定义。如果声明了一个*private*或*protected*嵌套类，这个类只能在外围类中使用。嵌套的类有权访问外围类中的所有*private*或*protected*成员；而外围类只能访问嵌套类中的*public*成员。

---

### 类内的枚举类型

```C++
emun class Color{red=1;green;blue;yellow}
```

---

### 创建稳定的接口

可创建清晰的接口，并隐藏所有实现细节，从而得到稳定的接口。基本原则是为想编写的每个类都定义两个类：接口类和实现类。实现类与已编写的类相同，接口类给出了与实现类一样的*public*方法，但只有一个数据成员：指向实现类对象的一个指针。这称为*pimpl idiom*或*bridge*模式，接口类方法的实现只是调用实现类对象的等价方法。这样做的结果是无论实现如何改变都不会影响*public*接口类，从而降低了重新编译的必要性。当实现改变时，使用接口类的客户不需要重新编译。

```C++
#include <memory>

class SpreadsheetApplication;

class Spreadsheet
{
    public:
        Spreadsheet(const SpreadsheetApplication& theApp,
            size_t width = kMaxWith, size_t height = kMaxHeight);
        Spreadsheet(const Spreadsheet& src);
        ~Spreadsheet();

        Spreadsheets operator=(const Spreadsheet& rhs);
        void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell); 
        SpreadsheetCell& getCellAt(size_t x, size_t y);
        size_t getId() const;

        scatic const size_t KMaxHeight = 100;
        static const size_t kMaxWidth = 100;

        friend void swap(Spreadsheet& frist, Spreadsheet& second) noexcept;

    private:
        class Impl;
        std::unique_ptr<Impl> mImpl;
}
```

实现类*Impl*是一个*private*嵌套类，因为只有*Spreadsheet*需要了解这个实现类。*Spreadsheet*现在只包含一个数据成员：指向*Impl*实例的指针。*public*方法与旧式的*Spreadsheet*相同。

```C++:
void Spreadsheet::Impl::swap(Impl& other) noexcept
{
    using std::swap;

    swap(mWidth, other.mWidth);
    swap(mHeight, other.mHeight);
    swap(mCells, other.mCells);
}
```

真正将接口和实现分离的技术功能强大。支持这种方法最有力的论证不是将接口分离的美感，而是类的实现改变后大幅缩短构建时间。

---

### 类的继承问题

#### 修改重写方法的特征

- 修改方法的返回类型
  根据经验，重写方法要使用与基类一致的方法声明（或方法原型）。实现可以改变，但原型保持不变。然而事实未必总是如此，在C++中，如果原始的返回类型是某个类的指针或引用，重写的方法可将返回类型改为派生类的指针或引用。这种类型称为协变返回类型（covariant return types）。如果基类和派生类处于平行层次结构（parallet hierarchy）中，使用这个特征可以带来便利。平行层次结构是指，一个类层次结构与另一个类层次结构没有相交，但是存在联系。
- 修改方法的参数
  如果在派生类的定义中使用父类中虚方法的名词，但参数与父类中同名方法的参数不同，那么这不是重写父类的方法，而是创建一个新方法。如果希望重写基类中的方法，就应该像前面建议的那么使用override关键字。可使用一种较晦涩的技术兼顾二者。也就是说，可使用这一技术在派生类中有效的用新的原型“重写”某个方法，并继承该方法的基类版本。这一技术使用using关键字显式地在派生类中包含这个方法的基类定义：
  
  ```C++
  class Base
  {
      public:
          virtual void someMethod();
  };
  
  class Derived : public Base
  {
      public:
          using Base::someMethod;  // explicitly inherits the base version
          virtual void someMethod(int i); // add a new version of somethod
          virtual void someOtherMethod();
  
  }
  ```

#### 继承的构造函数

可在派生类中使用using关键字显式的包含基类中定义的方法。

```C++
class Base
{
    public:
        virtual ~Base() = default;
        Base() = default;
        Base(std::string_view str);
};
class Derived : public Base
{
    public:
        using Base::Base;
        Derived(int i);
};
```

Derived类使用using关键字继承了Base类中除默认构造函数外的其他所有构造函数。
使用using子句从基类继承构造函数有一些限制。当从基类继承构造函数时，会继承除默认构造函数外的其他全部构造函数，不能只是继承基类构造函数的一个子集。第二个限制与多重继承有关，如果一个基类的某个构造函数与另一个基类的构造函数具有相同的参数列表，就不可能从基类继承构造函数，因为那样会导致歧义。

#### 重写方法的特殊情况

##### 静态积累方法

在C++中，不能重写静态方法。首先，方法不可能即是静态的又是虚的。出于这个原因，试图重写一个静态方法并不能得到预期的结果。如果派生类中存在的静态方法与基类中的静态方法同名，实际上这是两个独立的方法。
静态方法属于定义它的类，而不属于特定的对象。当类中的方法调用静态方法时，所调用的版本是通过正常的名词解析来决定。当使用对象调用时，对象实际上并不涉及调用，只是用来判断编译时的类型。

##### 重载基类方法

当指定名称喝一组参数以重写某个方法时，编译器隐式地隐藏基类中同名方法的所有其他实例。

```C++
// 如果重写给定名称的某个方法，可能时想重写所有的同名方法，
// 只是忘记这么做，因此应做错误处理。
class Base
{
    public:
        virtual ~Base() = default;
        virtual void overload(){ cout<<"Base's overload()"<<endl; }
        virtual void overload(int i){ 
            cout<<"Base's overload(int i)"<<endl; }
};
class Derived : public Base
{
    public:
        virtual void overload()override { cout<<"Derived's overload()"<<endl; }
};
// 以下代码无法编译。
Derived myDerived;
myDerived.overload(2);  // Error! No matching method for overload(int)
```

在C++中，隐藏未实现的重载方法只是表象，显式声明为子类型实例的对象无法使用这些方法，但可将其转换为基类类型，以使用这些方法。

##### private或protected基类方法

重写private或protexted方法当然没有问题。方法的访问说明符判断谁可以调用这些方法。派生类无法调用父类的private方法，并不意味着无法重写这个方法。在C++中，重写private或peotected方法时一种常见模式。这种模式允许派生类定义自己的“独特性”，在基类中会引用这种独特性。

```C++
class ME
{
    public:
        virtual ~ME() = defualt;
        virtual int getML(int i) const{
            return getMG() * i;
        }
    private:
        virtual int getMG() const{
            return 20;
        }
};
class EME : public ME
{
   private:
        virtual int getMG() const override {
            return 30;
        } 
};
```

重写private或protected方法可在不做重大改动的情况下改变类的某些特性。

##### 基类方法具有默认参数

派生类与基类可具有不同的默认参数，但使用的参数取决于声明的变量类型，而不是底层的对象。产生这种行为的原因是C++根据表达式的编译时类型（非运行时类型）绑定默认参数。在C++中，默认参数不会被“继承”。
当重写具有默认参数的方法时，也应该提供默认参数，这个参数的值应该与基类版本相同。

##### 派生类方法具有不同的访问级别

可以采用两种方法来修改方法的访问级别——可以加强限制，也可以放宽限制。
加强某个方法的限制，有两种方法，一种方法时修改整个基类的访问说明符；另外一种是在派生类中重新定义访问限制。
在派生类中放宽访问限制

```C++
class secret
{
    protected:
        virtual void dontTell() { cout<<"I'll never tell."<<endl; }
};
class blabber : public secret
{
    public:
        virtual void dontTell() {cout<<"I'll tell all."<<endl;}
        // 或者使用下面方法
        using secret::dontTell;
};
```

##### 派生类中的复制构造函数和赋值运算符

在类中使用动态内存分配时，提供复制构造函数和赋值运算符是良好的编程习惯。当定义派生类时，必须注意复制构造函数和operator=。



