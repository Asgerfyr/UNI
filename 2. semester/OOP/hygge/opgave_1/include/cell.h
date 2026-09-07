#include <string>

class Cell
{
  public:
  Cell();
  void set(bool player1);
  void force_set(bool player1);

  void reset();
  
  int get();
  bool get_filled();

  std::string to_string()const;

  private:
  bool _filled;
  bool _player1;
};