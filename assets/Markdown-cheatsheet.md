You can also use https://stackedit.io/ to easily create a markdown document.

# Header 1 
The code is `# title`.
## Sub Header
The code is `## title`.

# New Line
You can create a new paragraph by leaving a blank line between lines of text.


# Code
To put a code in mark down you can just wrap your code with \`\`\`
  > Example:
  ```
    ```C
      void test(){
        println('Hi');
      }
    ```
  ```
The following code will convert to: 
  ```C
      void test(){
        println('Hi');
      }    
  ```
  ## Inline Code
  You can call out code or a command within a sentence with single backticks. The text within the backticks will not be formatted.

  > Example ```Use `git status` to list all new or modified files that haven't yet been committed.```
  
  Use `git status` to list all new or modified files that haven't yet been committed.
    
  # Image
  You can create an inline Image by wrapping alt text in brackets `![ ]`, and then wrapping the Image in parentheses `( )`. 
  > Example `![Example](https://avatars3.githubusercontent.com/u/42888454?s=200&v=4)`  
  
  ![Example](https://avatars3.githubusercontent.com/u/42888454?s=200&v=4)
  
  You can define relative image paths in your repository.
  A relative image path is a path that is relative to the current file. For example, if you have a README file in root of your repository, and you have another image in `docs/photo.png`, the relative link to `photo.png` in your README might look like this:
  To put image just use the relate path to image:
  
  > `![Alt text](docs/photo.png?raw=true)`
  
  For example if an image is inside this folder, just use the image file name.
  
  > Example: `![Test](photo.png?raw=true)`
  
  ![Test Image](photo.png?raw=true)
  
  # Link
  You can create an inline link by wrapping link text in brackets [ ], and then wrapping the URL in parentheses ( ). 

  > Example `This site was built using [GitHub Pages](https://pages.github.com/).`
  
  This site was built using [GitHub Pages](https://pages.github.com/).
   
  You can define relative links and image paths in your rendered files to help readers navigate to other files in your repository.
  A relative link is a link that is relative to the current file. For example, if you have a README file in root of your repository, and you have another file in docs/CONTRIBUTING.md, the relative link to CONTRIBUTING.md in your README might look like this:

> Example `[Contribution guidelines for this project](docs/CONTRIBUTING.md)`

[Contribution guidelines for this project](docs/CONTRIBUTING.md)

# Lists

You can make an unordered list by preceding one or more lines of text with `-` or `*.`
> Example
```
- George Washington
- John Adams
- Thomas Jefferson
```
Rendered unordered list

- George Washington
- John Adams
- Thomas Jefferson



To order your list, precede each line with a number.
> Example 
```
1. James Madison  James Madison  James Madison  James Madison  James Madison  James Madison  James Madison  James Madison  James Madison  James Madison  James Madison  James Madison  James Madison  James Madison 
2. James Monroe
3. John Quincy Adams
```
1. James Madison  James Madison  James Madison  James Madison  James Madison  James Madison  James Madison  James Madison  James Madison  James Madison  James Madison  James Madison  James Madison  James Madison 
2. James Monroe
3. John Quincy Adams
# Other

Style|	Syntax	|Keyboard shortcut|	Example|	Output
-|-|-|-|-
Bold| `** **` or `__ __`	|`command/control` + `b`	|`**This is bold text**`|**This is bold text**
Italic|	`* *` or `_ _`	|`command/control` + `i`	|`*This text is italicized*`|*This text is italicized*
Strikethrough|	`~~ ~~`	||	`~~This was mistaken text~~`|~~This was mistaken text~~
Bold and nested italic|	`** **` and `_ _`		||`**This text is _extremely_ important**`|**This text is _extremely_ important**	
All bold and italic|	`*** ***`	||	`***All this text is important***`|***All this text is important***	

