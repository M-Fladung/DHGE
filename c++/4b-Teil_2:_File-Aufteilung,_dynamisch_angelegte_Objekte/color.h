class Color
{

public:
    Color(int r = 0, int g = 0, int b = 0)
    {
        mR = r;
        mG = g;
        mB = b;
    }

    int getR() const { return mR; }
    int getG() const { return mG; }
    int getB() const { return mB; }

private:
    int mR, mG, mB;
};