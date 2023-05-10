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


