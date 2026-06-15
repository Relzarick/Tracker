#pragma once

#include <FL/Fl_Input_.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Window.H>

class InputField : public Fl_Input {
public:
  InputField(int, int, int, int);
  int handle(int) override;

private:
  void styleInput(Fl_Boxtype, Fl_Color);
};

class BigInputField : public Fl_Multiline_Input {
public:
  BigInputField(int, int, int, int);
  int handle(int) override;

private:
  void styleInput(Fl_Boxtype, Fl_Color);
  int KeyboardInputs(int);
  int handleFormat(int);

  int maxRows = 5;
  int lineSize = 49;
};

class Window : public Fl_Window {
public:
  Window(int w, int h, const char *title);
  int handle(int) override;
};