#include <ostream>

class Kapacitor
{
    public:
    Kapacitor(const double kapacitans);
    friend std::ostream & operator<<(std::ostream &os, Kapacitor kapacitor);
    friend Kapacitor operator|(Kapacitor left, Kapacitor right);
    friend Kapacitor operator&(Kapacitor left, Kapacitor right);

private:
    double kapacitans_;
    static double lower_bound_;
};

std::ostream & operator<<(std::ostream &os, Kapacitor kapacitor);
Kapacitor operator|(Kapacitor left, Kapacitor right);
Kapacitor operator&(Kapacitor left, Kapacitor right);