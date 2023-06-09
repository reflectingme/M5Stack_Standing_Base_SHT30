# Alternate Code for M5Stack BCT Standing Base

NB: Please note I am not a professional coder, you are free to use this code as you wish but its use is entirely at your own risk.  

This is a very simple alternate script, modified from the original M5Stack code for the SHT30 temperature and pressure sensor contained in the BCT Standing Base unit for the M5Stack module.  It is not meant to be anything grand, simply a straightforward replacement for the M5Stack demo code for the BCT Standing Base.

If you do experience any problems with the code, or if you have suggestions as to how this very basic code could be improved (please remember I am simply a self taught developer, and most certainly not a seasoned professional), please do get in touch, I will respond to any issues reported as and when I am able to.

 ## What running this code should look like on your M5Stack screen

 This is what you should see on your M5Stack screen when running the code in this repository.

 ![M5Stack screen output](/screenshots/M5Stack_Standing_Base.jpg)

 ... and this is what you should see on your screen when running the original factory code.

 ![M5Stack original screen output](/screenshots/M5Stack_Standing_Base_original.jpg)

 I have not added anything complex, I simply use some of the graphics methods already included in the M5Stack.h library.


Make sure you have the correct and up-to-date libraries installed for the M5Unit-Env.  The correct files for the ENVIII devices including the SHT30 are available from M5Stack here:

https://github.com/Tinyu-Zhao/M5Unit-ENV

M5Stack have moved the original code for the BTC Standing Base unit to a pubclic archive, the code is still available here: 

https://github.com/m5stack/M5-ProductExampleCodes/tree/master/Base/BTC/Arduino/BTC2.1

M5Stack product page:

https://docs.m5stack.com/en/base/btc_base

NOTE: If you have been experiencing issues getting the M5Stack Standing Base to show any temperature or humidity data readings, you may need to remove the original M5Unit-ENV folder from your /libraries flder then pull and replace the whole library with the one from the above URL.

John.

Enjoy! :smile: