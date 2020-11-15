void display_start();
void draw_circle(int x,int y, int radius, bool fill);
void draw_rectangle(int x0, int y0, int x1, int y1, bool fill);
void draw_triangle(int x0,int y0, int x1, int y1, int x2, int y2,bool fill);
void draw_text(String str);
void draw_pixel(int x,int y);
void font_size(int num);
void draw_line(int x0,int y0, int x1, int y1);
void cursor(int x,int y);
void clear();
void draw_temperature_box(int temp);
void draw_humidity_box(float value);
void draw_welcome();
void draw_warning();
void draw_text_box(String text);
void draw_alarm(String text1,String text2);
