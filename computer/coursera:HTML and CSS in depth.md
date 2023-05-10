### HTML Meta Tags

---

* Meta tags provide data about a web page, such as title, author, keyword,etc.
* They also peovide instructions to the browser, such as, how to display content.
* Meta tags are not visible to users.

#### Example

```HTML
<head>
    <meta charset="UTF-8">
    <meta name="title" content=""Vincent van Gogh's early lifr>
    <meta name="description" content="Early life of van Gogh as a budding painter">
    <meta name="keyword" content="Vincent, van Goph, Dutch, painter, young, early life">
    <meta name="author" content="Deborah Anderson">
    <meta name="viewport" content="with=device-with, initial-scale=1.0">
</head>
```

#### Using Meta

* All \<meta> tags are placed inside \<head> element.
* Meta data is passed as *name/content* pairs, that is, name/value pairs.
* if a name or http-equiv attribute is defined then the content attribute must have a value.
* Meta data is used by browser to optimally render the page. User will not see this data.
* Meta data can alse help pages rank better with seach engines.

#### Attributes

| ATTIBUTE | VALUE | DESCRIPITON |
| :------: | :---- | :---------- |
| charset | chaeacter-set | Specifies the character encoding for thr HTML document |
| content | value | Sets the value for the accociated http-equiv or name attribute |
| http-equiv | content-type default-style refresh | Set an HTTP header for the value of the content attribute |
| name | application-name author description generator keyword viewport | Set the name for the metadata. The value is given in the content attribute. |

#### Tittle Meta

* The tittle meta value specifies the tittle of the page.
* As an end-user the tittle value is not easy to see.
* It shows up in the page tab, often with a tooltip to display the entire tittle.
* The tittle is very important for Search Engine Optimization.

#### Description Meta

* The description meta value specifies the content of the page.
* It make it easier for search engines to determine what the page is about.
* The Description can be important for Search Engin Optimization.

#### Keyword Meta

* The keyword meta value specifies a number of keyword about the page.
* Keyword are comma separated list of keywords that represent the content of the page.
* The keywrds can be important for SEO but less so than the tittle and description.

#### Author Meta

The autor meta value specifies the author of the page. it can be a person or an organization.

#### Viewport Meta

* The viewport meta value specifies the visible area of the page.
* Viewport vary by device and are smaller on a mobile phone than a computer screen.
* The viewport meta tag informs the browser how to control the demension and scaling of a page.

#### Code explanation

* The width=device-width sets the page width to be the same as the device width
* The initial-scale=1.0 sets the initial zoom level to 100% when the page is loaded.

### Semantic HTML5 Elements Explained

---

#### List of new semantic elements

The semantic elements added in HTML5 are:

* \<article>
* \<aside>
* \<details>
* \<figcaption>
* \<footer>
* \<header>
* \<main>
* \<mark>
* \<nav>
* \<section>
* \<summary>
* \<time>

Elements such as \<header>, \<nav>, \<section>, \<article>, \<aside> and \<footer> act more or less like \<div> element. They group other elements together into page sections. However where a \<div> tag could contain any type of information, it is easy to indentify what sort of information would go in the semantic \<header> regin.

#### \<section> and \<article>

Both these elements are used for sctioning a content, and yes, they can definitely be used interchangeably. To decide which of these you should choose, take note of the following:

1. An article is intended to be independently distributable or reusable.
2. A section is a thematic grouping of content.

```HTML
<section>
    <p>Top Stories</p>
    <section>
        <article>story 1</article>
        <article>story 2</article>
    </section>
    <section>
        <p>sort</p>
        <article>story 1</article>
        <article>story 2</article>
    </section>
</section>
```

#### \<header> and \<hgroup>

The \<header> element is generally found at the top of a document, a section, or an article and usually contains the main heading and some navigation and search tools.

```html
<header>
    <h1>Company A</h1>
    <ul>
        <li><a href="/home">Home</li>
        <li><a href="/about">About</li>
        <li><a href="/contact">Contact us</li>
    </ul>
    <form target="/search">
        <input name="q" type="search" />
        <input type="submit" />
    </form>
</header>
```

The \<hgroup> element should be used where you want a main heading with one or more subheadings.

```html
<hgroup>
    <h1>Heading 1</h1>
    <h2>subheading 2</h2>
    <h2>subheading 2</h2>
</hgroup>
```

<b>REMENBER</b>, that the \<header> element can contain any content, but the \<hgroup> element can only contain other headers, that is \<h1> to \<h6> and including \<hgroup>.

#### \<aside>

The \<aside> element is intended for content that is not part of the flow of the text in which it appears, however still related in some way. this of \<aside> as a sidebar to your main content.

#### \<footer>

If there is a \<header> there must be a \<footer>. A \<footer> is generally found at the bottom of a document, a section, or an article. Just like the \<header> the content is generally mentainformation, such as author details, legal information, and/or links to related information. It is also valid to include \<section> elements within a footer.

#### \<small>

The \<small> element often appears within a \<footer> or \<aside> element which would usually contain copyright information or legal disclaimers, and other such fine print. However, this is not intend to make the text smaller, it is just describing its content, not prescribing presentation.

```html
<footer><small>&copy; Company A</small> Date</footer>
```

#### \<time>

The \<time> element allows an unambiguous ISO 8601 date to be attached to a human-readeble version of that data.

```html
<time datetime="2017-10-31T11:21:00+02:00">Teusday, 31 October 2017</time>
```

### How to add twitter card and open graph social metadata to you webpage with HTML

---

When you share links on social media platforms, they will often be presented with rich imagery and a nicely formatted tittle, summary, and link, instead of plain text. You can add thesr rich media social sharing capablilities to you site by including certain \<meta> tags in the \<header> of you HTML document. There are two main standards that determine how to format this metadata: Twitter Cards and the Open Graph Protocol.

#### Adding twitter card metadata to a webpage

To add basic Twitter card metadata to you site, place the following \<meta> tags in between your existing \<header> and \</header> tags:

```html
<meta name="twitter:card" content="summary_large_image" />
<meta name="twitter:site" content="@digitalocean" />
<meta name="twitter:title" content="sammy the shark" />
<meta name="twitter:description" content="senior selachimorpha at digitalocean" />
<meta name="twitter:image" content="https://html.sammy-codes.com/images/large-profile.jpeg" />
```

Let's walk throught each tag we just added:

* `twitter:card`: this tag specifies the type of Twitter card taht should be display. the `sumary_large_image*`type display a short summary with a large image preview.
* `twitter:site`: you Twitter username, or your site or company's name.
* `twitter:title`: the title you'd like used in the card. This could match what you've put in your `\<title>` tags. but it doesn't have to.
* `twitter:description`: a brief description of the page that will be displayed under the title. This should be maximum of 200 characters.
* `twitter:image`: an image to show. Most standard image formats are acceptable, but it must be less than 5MB in size.

#### Adding open graph metadata to a webpage

```html
<meta property="og:type" content="article" />
<meta property="og:title" content="Sammy the Shark" />
<meta property="og:description" content="Senior Selachimorpha at DigitalOcean" />
<meta property="og:url" content="https://html.sammy-codes.com/" />
<meta property="og:image" content="https://html.sammy-codes.com/images/large-profile.jpg" />
```

The tags you'll need are:

* `og:type`: the "type" of the content being described. some `type` examples are `article`, `book`, `profile`.
* `og:title`: the title of the page.
* `og:description`: a short description of the page.
* `og:url`: the permanent URL of the page.
* `og:image`: an image to associate with the page.

#### Social media analytics

What Facebook is indicating is that if you're going to use their analytics tool, which they call `Domain Insights` you must provide the unique ID number associated with your account.

```html
<meta property="fb:app_id" content="you_app_id" />
```

Twitter has something similar that they call `Twitter card analytics`.

```html
<meta name="twitter:site" content="@website-username" />
```

### \<meta> The metadata element

---

The \<meta> HTML element represents metadata that can not be represented by other HTML meta-related elements, like \<base>, \<link>, \<script>, \<style> or \<title>.

The type metadata provided by the \<meta> element can be one of the following:

* if the `name` attribute is set, the `\<meta>` element provides *document-level metadata* applying to the whole page.
* if the `http-equiv` attribute is set, the `\<meta>` element is a *pragma directive*, providing information equivalent to what can be given bu a similarly-named HTTP header.
* if the `charset` attribute is set, the element is a *charset declaration*, given the character encoding in which the document is encodes.
* if the `itemprop` attribute is set, the element provides *user-defined metadata*.

### How to use Bootstrap with HTML

---

Bootstrap is an open-source HTML, CSS and javascript framework that makes UI development easier with pre-built responsive classes and other utilities.

#### Prerequisties

have basic knowledge of HTML/CSS and JS.

#### Getting started

##### 1. Using Bootstrap CDN

**CSS**
Simply copy this stylesheet link to the \<head> of your HTML file.

```html
<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
```

**JS**
The javascript functionalities of some components like dropdowns, tabs, etc depend on jQuery and popper.js

```html
<script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>

<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>

<script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
```

##### 2. Downloading the files locally

Instead of using CDN, you can download the files locally to your project folder from [https://getbootstrap.com/docs/4.3/getting-started/download/](https://getbootstrap.com/docs/4.3/getting-started/download/)
Once you download the file, you can include the bootstrap.min.css file the \<head> and bootstrap.min.js in \<body>. Even if you are using the download bootstrap file, you have to include jquery.min.js and popper.min.js before loading bootstrap.min.js

##### 3. Using package managers

```shell
npm install bootstrap
```

**Usage**

```html
<!doctype html>
<html lang="en">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
    <title>Bootstrap example</title>
</head>
  <body> 
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
  </body>
</html>
```

Once you have included Bootstrap in your project using any of the above methods, you can use all the components available in bootstrap easily.

A well-arranged navbar can be easily built with bootstrap by adding the following HTML markup:

```html
<nav class="navbar navbar-expand-lg navbar-light bg-light">
  <a class="navbar-brand" href="#">Navbar</a>
  <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
    <span class="navbar-toggler-icon"></span>
</button>
  <div class="collapse navbar-collapse" id="navbarSupportedContent">
    <ul class="navbar-nav mr-auto">
      <li class="nav-item active">
        <a class="nav-link" href="#">Home <span class="sr-only">(current)</span></a>
      </li>
      <li class="nav-item">
        <a class="nav-link" href="#">Link</a>
      </li>
      <li class="nav-item dropdown">
        <a class="nav-link dropdown-toggle" href="#" id="navbarDropdown" role="button" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
          Dropdown
        </a>
        <div class="dropdown-menu" aria-labelledby="navbarDropdown">
          <a class="dropdown-item" href="#">Action</a>
          <a class="dropdown-item" href="#">Another action</a>
          <div class="dropdown-divider"></div>
          <a class="dropdown-item" href="#">Something else here</a>
        </div>
      </li>
      <li class="nav-item">
        <a class="nav-link disabled" href="#" tabindex="-1" aria-disabled="true">Disabled</a>
      </li>
    </ul>
    <form class="form-inline my-2 my-lg-0">
      <input class="form-control mr-sm-2" type="search" placeholder="Search" aria-label="Search">
      <button class="btn btn-outline-success my-2 my-sm-0" type="submit">Search</button>
    </form>
  </div>
</nav>
```

This code produces a navbar in the following style, that too without writing a single CSS or JS on your own!

[EXAMPLE](https://getbootstrap.com/docs/5.2/examples/): quickly get a project started with any of our examples ranging from using parts of the framework to custom components and layouts.

### Client-Side from validation with HTML5

---

HTML5 includes a fairly solid form validation mechanism powered by th following `<input />` attribute: `type`, `pattern`, `require`. you can delegate some data verification function to the browser.

* the `type` attribute.
* the `pattern` attribute.
* giving hints.
  
  ```html
  <input type="text" name="ssn" 
         pattern="^\d{3}-\d{2}-\d{4}">
         title="the social security number" />
  ```
* the `required` attribute

### \<input> 输入（表单输入）元素

---

HTML \<input> 元素为基于Web的表单创建交互式控件，以便接受来自用户的数据，可以使用各种类型的输入数据和控件小部件。

#### \<input> types

\<input>的工作方式相当程度上取决于`type`属性值，如果未制定，则采取默认类型为text

* button 没有默认值，显示`value`属性的值，默认为空。
* checkbox
* color
* date
* datetime-local
* email
* hidden
* image
* month
* number
* password
* radio
* range
* reset
* search
* submit
* tel
* text
* time
* url
* week



