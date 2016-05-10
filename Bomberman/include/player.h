#ifndef PLAYER_H
#define PLAYER_H


class player
{
    public:
        player();
        player(unsigned int val_x, unsigned int val_y);
        virtual ~player();

        unsigned int Get_x() const;
        void Set_x(unsigned int val);
        unsigned int Get_y() const;
        void Set_y(unsigned int val);

    protected:

    private:
        unsigned int m_x;
        unsigned int m_y;
};

#endif // PLAYER_H
