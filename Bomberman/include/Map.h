#ifndef MAP_H
#define MAP_H
#include <vector>

class Map
{
    public:
        Map();
        Map(int height, int width);
        ~Map();

        unsigned int Get_height() { return m_height; }
        //void Set_height(unsigned int val) { m_height = val; }
        unsigned int Get_width() { return m_width; }
        //void Set_width(unsigned int val) { m_width = val; }

        bool loadLayout();

        unsigned int m_height;
        unsigned int m_width;
        std::vector<std::vector<char>> m_layout;
    protected:

    private:
};

#endif // MAP_H
