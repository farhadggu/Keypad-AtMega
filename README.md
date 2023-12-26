## Interface Keypad with Arduino in Proteus ISIS and AtmelStudio

How keypad works ??

Keypad uses matrix system in order to work.

For example, I am using a keypad which has 12 buttons

<img src="https://images.theengineeringprojects.com/image/webp/2015/12/keypad2.png.webp?ssl=1"]

Now you can see its a 12 button keypad so it has total 3 columns and 4 rows and similarly there are 7 pins to control these 12 buttons.

So, the simple formula is total number of pins = Number of Rows + Number of Columns.

Columns and rows are connected with each other now suppose I press button "1" on the keypad then first row and the first column will get short and I will get to know that button "1" is pressed.

Same is the case with other buttons, for example I press button "8" then second column and the third row will get short so this code will remain unique for each button.

In simple words, on each button press different column and row will get short we need to detect which one gets short in order to get the pressed button.
