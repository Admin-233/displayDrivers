老五数码之家买的4.2寸三色墨水屏

白黑红

分辨率400x300

测试平台esp8266

接线参考

https://www.waveshare.net/wiki/E-Paper_ESP8266_Driver_Board#.E6.96.87.E6.A1.A3

https://www.waveshare.net/w/upload/7/7e/ESP8266_e-paper.pdf

驱动思路：

​	结合评论区大佬说的，到微雪驱动里试

​	epd2in13b_V4-demo可以同时显示黑红两色

​	epd4in2_V2-demo可以完美驱动黑色，刷新所有像素

​	epd4in2b_V2-demo理论上可以驱动同分辨率三色的屏

于是复制epd2in13b_V4-demo的启动参数再把epd4in2_V2-demo部分函数和命令混合到epd4in2b_V2-demo就可以了