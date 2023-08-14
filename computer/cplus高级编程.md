# C++高级编程

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

##### 重载基类方法

在C++中，隐藏未实现的重载方法只是表象，显式声明为子类型实例的对象无法使用这些方法，但可将其转换为基类类型，以使用这些方法。

