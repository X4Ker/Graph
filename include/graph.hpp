#include <iostream>
#include <sstream>
#include <vector>
#include<string>
#include<stdexcept>

class graph_t
{
private:
    unsigned count_of_verticals;
    bool ** data;
public:
    graph_t(unsigned N)
    {
        count_of_verticals = N;
        data = new bool * [count_of_verticals];
        for (std::size_t i = 0; i < count_of_verticals; ++i)
        {
            data[i] = new bool [count_of_verticals];
        }
    }

    graph_t()
    {
        count_of_verticals = 0;
        data = nullptr;
    }

    graph_t & operator=(graph_t const &) = delete;

    graph_t(graph_t const &) = delete;

    ~graph_t()
    {
        for (std::size_t i = 0; i < count_of_verticals; ++i)
        {
            delete[] data[i];
        }
        delete[] data;
    }

    unsigned size_count_of_verticals()
    {
        return count_of_verticals;
    }

    void read(std::istringstream& stream);

private:
    void help(unsigned index, std::vector<unsigned> & used, std::vector<unsigned> & res)
    {
        used[index] = true;
        res.push_back(index + 1);
        for (unsigned j = 0; j < count_of_verticals; j++) {
            if (data[index][j])
            {
                if (!(used)[j])
                {
                    help(j, used, res);
                }
            }
        }
    }

public:
    void res_graph(std::ostream & ostream, std::vector<unsigned> res);

    std::vector<unsigned> dfs(unsigned index)
    {
        std::vector<unsigned> used, res;
        used.reserve(count_of_verticals);
        for (unsigned i = 0; i < count_of_verticals; i++) {
            used.push_back(false);
        }
        help(index, used, res);
        return res;
    }
};

void graph_t::read(std::istringstream& stream)
{
    for (std::size_t i = 0; i < count_of_verticals; i++)
    {
        for (std::size_t j = 0; j < count_of_verticals; j++)
        {
            unsigned a;
            if (stream >> a)
            {
                if (a == 1 || a == 0)
                {
                    data[i][j] = a;
                }
                else throw std::invalid_argument("Error 1");
            }
        }
        if (data[i][i] != 0)
        {
            throw std::invalid_argument("Error 2");
        }
    }
}

void graph_t::res_graph(std::ostream & ostream, std::vector<unsigned> res)
{
    for (unsigned i : res)
    {
        ostream << i << ' ';
    }

}
