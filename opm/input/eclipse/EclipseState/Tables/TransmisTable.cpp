#include <opm/input/eclipse/Deck/DeckItem.hpp>
#include <opm/input/eclipse/Deck/DeckKeyword.hpp>
#include <opm/input/eclipse/Deck/DeckRecord.hpp>
#include <opm/input/eclipse/EclipseState/Tables/TransmisTable.hpp>

namespace Opm {
    TransmisTable::TransmisTable(const DeckKeyword& kw) {
        faceFlux_.resize(kw.size());
        multiplier_.resize(kw.size());
        for (size_t ntab = 0; ntab < kw.size(); ++ ntab) {
            auto raw_data = kw.getRecord(ntab).getDataItem().getData<double>();

            int nrows = raw_data.size() / 2;
            faceFlux_[ntab].reserve(nrows);
            multiplier_[ntab].reserve(nrows);

            if (nrows <= 1) {
                throw std::logic_error("TRANSMIS ERROR: table rows must be greater than 1");
            }

            for (size_t i = 0; i < raw_data.size(); i += 2) {
                faceFlux_[ntab].push_back(raw_data[i]);
                multiplier_[ntab].push_back(raw_data[i + 1]);
            }
        }
    }

    size_t TransmisTable::size() {
        return faceFlux_.size();
    }

    const std::vector<double>& TransmisTable::getFaceFlux(int tableIdx) const {
        return faceFlux_[tableIdx];
    }

    const std::vector<double>& TransmisTable::getMultiplier(int tableIdx) const {
        return multiplier_[tableIdx];
    }
}
