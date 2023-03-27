
//
// Created by Hayden Collins on 3/26/23.
//

#ifndef M3AP_HCOLLIN3_PLANT_H
#define M3AP_HCOLLIN3_PLANT_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

class Plant {
private:
    std::string plantName, plantType;
    int rowId, utilityId;
    double installationYear, capacityMw, peakDemandMw, plantHoursConnectedWhileGenerating;
    double netCapacityFavorableConditionsMw, netCapacityAdverseConditionsMw, netGenerationMwh;

public:
    Plant();

    Plant(int rowId, int utilityId, std::string plantName, std::string plantType, double installationYear,
          double capacityMw, double peakDemandMw, double plantHoursConnectedWhileGenerating,
          double netCapacityFavorableConditionsMw, double netCapacityAdverseConditionsMw, double netGenerationMwh);

    int getRowId() const;

    int getUtilityId() const;

    std::string getPlantName() const;

    std::string getPlantType() const;

    double getInstallationYear() const;

    double getCapacityMw() const;

    double getPeakDemandMw() const;

    double getPlantHoursConnectedWhileGenerating() const;

    double getNetCapacityFavorableConditionsMw() const;

    double getNetCapacityAdverseConditionsMw() const;

    double getNetGenerationMwh() const;

    void setRowId(int rowId);

    void setUtilityId(int utilityId);

    void setPlantName(std::string plantName);

    void setPlantType(std::string plantType);

    void setInstallationYear(double installationYear);

    void setCapacityMw(double capacityMw);

    void setPeakDemandMw(double peakDemandMw);

    void setPlantHoursConnectedWhileGenerating(double plantHoursConnectedWhileGenerating);

    void setNetCapacityFavorableConditionsMw(double netCapacityFavorableConditionsMw);

    void setNetCapacityAdverseConditionsMw(double netCapacityAdverseConditionsMw);

    void setNetGenerationMwh(double netGenerationMwh);

    friend std::ostream &operator<<(std::ostream &outs, const Plant &obj);

    friend bool operator<(const Plant &lhs, const Plant &rhs);

    friend bool operator>(const Plant &lhs, const Plant &rhs);

    friend bool operator<=(const Plant &lhs, const Plant &rhs);

    friend bool operator>=(const Plant &lhs, const Plant &rhs);

    friend bool operator==(const Plant &lhs, const Plant &rhs);

    friend bool operator!=(const Plant &lhs, const Plant &rhs);

};


#endif //M3AP_HCOLLIN3_PLANT_H
