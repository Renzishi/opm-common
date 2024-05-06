#ifndef OPM_PARSER_TRANSMIS_TABLE_HPP
#define	OPM_PARSER_TRANSMIS_TABLE_HPP

#include <cstddef>
#include <vector>

namespace Opm {

    class DeckKeyword;

    class TransmisTable {
    public:
        TransmisTable() = default;
        TransmisTable(const DeckKeyword& kw);

        size_t size();

        const std::vector<double>& getFaceFlux(int tableIdx) const ;

        const std::vector<double>& getMultiplier(int tableIdx) const ;

    private:
        std::vector<std::vector<double>> faceFlux_;
        std::vector<std::vector<double>> multiplier_;
    };
}

#endif
