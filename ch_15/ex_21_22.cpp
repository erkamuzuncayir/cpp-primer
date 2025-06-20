// -----------------------------------------------------------------------------
// File:        ex_21_22.cpp
// Author:      Erkam Uzuncayir
// Date:        20/06/2025
// -----------------------------------------------------------------------------

#include <string>

class GraphicalFileFormat
{
public:
    GraphicalFileFormat() = default;
    GraphicalFileFormat(std::string f_n, int x, int y) : file_name(f_n), res_x(x), res_y(y) {}
    GraphicalFileFormat(const GraphicalFileFormat &other);

    virtual bool        compress();
    virtual bool        decompress();
    virtual void        render();
    virtual std::string get_name();
    virtual std::string get_res();

    virtual ~GraphicalFileFormat() = default;

private:
    std::string file_name;
    int         res_x;
    int         res_y;
};

class RasterFileFormat : public GraphicalFileFormat
{
public:
    RasterFileFormat() = default;
    RasterFileFormat(std::string f_n, int x, int y) : GraphicalFileFormat(std::move(f_n), x, y) {}

    ~RasterFileFormat() = default;
};

class PNGFileFormat : public RasterFileFormat
{
public:
    PNGFileFormat() = default;
    PNGFileFormat(std::string f_n, int x, int y) : RasterFileFormat(std::move(f_n), x, y) {}

    ~PNGFileFormat() = default;
};
