/**
 * Hayden Collins
 * CS 124
 * Section OL1
 */

#ifndef Plant_H
#define Plant_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

//Plant class
class Plant {

private:
    std::string plantName, plantType;
    int rowId, utilityId;
    double installationYear, capacityMw, peakDemandMw, plantHoursConnectedWhileGenerating;
    double netCapacityFavorableConditionsMw, netCapacityAdverseConditionsMw, netGenerationMwh;

public:
    // Constructors
    Plant() {
    }

    Plant(int rowId,
          int utilityId,
          std::string plantName,
          std::string plantType,
          double installationYear,
          double capacityMw,
          double peakDemandMw,
          double plantHoursConnectedWhileGenerating,
          double netCapacityFavorableConditionsMw,
          double netCapacityAdverseConditionsMw,
          double netGenerationMwh) {
        this->rowId = rowId;
        this->utilityId = utilityId;
        this->plantName = plantName;
        this->plantType = plantType;
        this->installationYear = installationYear;
        this->capacityMw = capacityMw;
        this->peakDemandMw = peakDemandMw;
        this->plantHoursConnectedWhileGenerating = plantHoursConnectedWhileGenerating;
        this->netCapacityFavorableConditionsMw = netCapacityFavorableConditionsMw;
        this->netCapacityAdverseConditionsMw = netCapacityAdverseConditionsMw;
        this->netGenerationMwh = netGenerationMwh;
    }

    // Getters
    int getRowId() const {
        return rowId;
    }

    int getUtilityId() const {
        return utilityId;
    }

    std::string getPlantName() const {
        return plantName;
    }

    std::string getPlantType() const {
        return plantType;
    }


    double getInstallationYear() const {
        return installationYear;
    }

    double getCapacityMw() const {
        return capacityMw;
    }

    double getPeakDemandMw() const {
        return peakDemandMw;
    }

    double getPlantHoursConnectedWhileGenerating() const {
        return plantHoursConnectedWhileGenerating;
    }

    double getNetCapacityFavorableConditionsMw() const {
        return netCapacityFavorableConditionsMw;
    }

    double getNetCapacityAdverseConditionsMw() const {
        return netCapacityAdverseConditionsMw;
    }

    double getNetGenerationMwh() const {
        return netGenerationMwh;
    }

    // Setters
    void setRowId(int rowId) {
        this->rowId = rowId;
    }

    void setUtilityId(int utilityId) {
        this->utilityId = utilityId;
    }

    void setPlantName(std::string plantName) {
        this->plantName = plantName;
    }

    void setPlantType(std::string plantType) {
        this->plantType = plantType;
    }

    void setInstallationYear(double installationYear) {
        this->installationYear = installationYear;
    }

    void setCapacityMw(double capacityMw) {
        this->capacityMw = capacityMw;
    }

    void setPeakDemandMw(double peakDemandMw) {
        this->peakDemandMw = peakDemandMw;
    }

    void setPlantHoursConnectedWhileGenerating(double plantHoursConnectedWhileGenerating) {
        this->plantHoursConnectedWhileGenerating = plantHoursConnectedWhileGenerating;
    }

    void setNetCapacityFavorableConditionsMw(double netCapacityFavorableConditionsMw) {
        this->netCapacityFavorableConditionsMw = netCapacityFavorableConditionsMw;
    }

    void setNetCapacityAdverseConditionsMw(double netCapacityAdverseConditionsMw) {
        this->netCapacityAdverseConditionsMw = netCapacityAdverseConditionsMw;
    }

    void setNetGenerationMwh(double netGenerationMwh) {
        this->netGenerationMwh = netGenerationMwh;
    }

    /**
     * Overload stream insertion operator for pretty printing
     */
    friend std::ostream &operator<<(std::ostream &outs, const Plant &obj) {
        outs << std::fixed
             << std::right
             << std::setprecision(4)
             << std::setw(6) << obj.getRowId()
             << std::setw(12) << obj.getUtilityId()
             << std::left
             << "  "
             << std::setw(20) << obj.getPlantName()
             << std::setw(18) << obj.getPlantType()
             << std::right
             << std::setprecision(0)
             << std::setw(13) << obj.getInstallationYear()
             << std::setprecision(1)
             << std::setw(16) << obj.getCapacityMw()
             << std::setw(13) << obj.getPeakDemandMw()
             << std::setw(15) << obj.getPlantHoursConnectedWhileGenerating()
             << std::setw(15) << obj.getNetCapacityAdverseConditionsMw()
             << std::setw(15) << obj.getNetCapacityFavorableConditionsMw()
             << std::setw(15) << obj.getNetGenerationMwh();
        return outs;
    }

    // for future projects

    /**
     * Overload < operator for object comparison
     */
    friend bool operator<(const Plant &lhs, const Plant &rhs) {
        return lhs.getCapacityMw() < rhs.getCapacityMw();
    }

    /**
     * Overload > operator for object comparison
     */
    friend bool operator>(const Plant &lhs, const Plant &rhs) {
        return lhs.getCapacityMw() > rhs.getCapacityMw();
    }

    /**
     * Overload <= operator for object comparison
     */
    friend bool operator<=(const Plant &lhs, const Plant &rhs) {
        return lhs.getCapacityMw() <= rhs.getCapacityMw();
    }

    /**
     * Overload >= operator for object comparison
     */
    friend bool operator>=(const Plant &lhs, const Plant &rhs) {
        return lhs.getCapacityMw() >= rhs.getCapacityMw();
    }

    /**
     * Overload == operator for object comparison
     */
    friend bool operator==(const Plant &lhs, const Plant &rhs) {
        return lhs.getCapacityMw() == rhs.getCapacityMw();
    }

    /**
     * Overload != operator for object comparison
     */
    friend bool operator!=(const Plant &lhs, const Plant &rhs) {
        return lhs.getCapacityMw() != rhs.getCapacityMw();
    }

};

// Other functions

void capacityStats(std::vector<Plant> &objs) {
    double sum = 0;
    Plant maxPlant, minPlant;

    //finding min/max/sum/avg
    for (Plant &plant : objs) {
        if (plant.getCapacityMw() > maxPlant.getCapacityMw()) {
            maxPlant = plant;
        }
        if (plant.getCapacityMw() < minPlant.getCapacityMw()) {
            minPlant = plant;
        }
        sum += plant.getCapacityMw();
    }
    double avg = sum / objs.size();

    //printing table
    std::cout << std::endl;
    std::cout << std::string(100, '-') << std::endl;
    std::cout << "The largest plant is "
              << maxPlant.getPlantName()
              << " with a capacity of "
              << maxPlant.getCapacityMw()
              << " MW"
              << std::endl
              << "The smallest plant is "
              << minPlant.getPlantName()
              << " with a capacity of "
              << minPlant.getCapacityMw()
              << " MW"
              << std::endl
              << "The total capacity of all plants in this dataset is "
              << sum
              << " MW"
              << std::endl
              << "The average capacity of all plants in this dataset is "
              << std::setprecision(4)
              << avg
              << " MW"
              << std::endl;
}

/**
 * Read data into a vector from the downloaded CSV file.
 * Returns true if everything goes well; false otherwise.
 */
bool loadFromFile(std::string fn, std::vector<Plant> &objs) {
    std::ifstream fin;
    fin.open(fn);

    if (!fin) {
        // Bad file / could not open
        return false;
    }

    // Get rid of the header line: read it and throw it away
    std::string header = "";
    getline(fin, header);

    //reading data until EOF
    int counter = 1;
    while (fin && fin.peek() != EOF) {
        //initializing to sentinels
        int rowId = -1;
        int utilityId = -1;
        std::string plantName = "INVALID";
        std::string plantType = "INVALID";
        double installationYear = -1.0;
        double capacityMw = -1.0;
        double peakDemandMw = -1.0;
        double plantHoursConnectedWhileGenerating = -1.0;
        double netCapacityFavorableConditionsMw = -1.0;
        double netCapacityAdverseConditionsMw = -1.0;
        double netGenerationMwh = -1.0;
        char comma = ',';

        // Using the >> (extraction) operator ...
        fin >> rowId;
        if (rowId != counter) {
            std::cout << rowId << " != " << counter << std::endl;
            return false;
        }
        fin >> comma;
        fin >> utilityId;
        fin >> comma;
        getline(fin, plantName, comma);
        getline(fin, plantType, comma);
        fin >> installationYear;
        fin >> comma;
        fin >> capacityMw;
        fin >> comma;
        fin >> peakDemandMw;
        fin >> comma;
        fin >> plantHoursConnectedWhileGenerating;
        fin >> comma;
        fin >> netCapacityFavorableConditionsMw;
        fin >> comma;
        fin >> netCapacityAdverseConditionsMw;
        fin >> comma;
        fin >> netGenerationMwh;

        Plant plant(rowId, utilityId, plantName, plantType,
                    installationYear, capacityMw, peakDemandMw,
                    plantHoursConnectedWhileGenerating, netCapacityFavorableConditionsMw,
                    netCapacityAdverseConditionsMw, netGenerationMwh);
        objs.push_back(plant);
        counter += 1;
    }
    fin.close();
    return true;
}

//value testing
void verifyAllFieldsSet(std::vector<Plant> &objs) {
    int i = 0;
    for (Plant &plant : objs) {
        // Row ID should always = i + 1
        if (plant.getRowId() != i + 1) {
            std::cout << "Bad value for row ID at record "
                      << i << std::endl;
        }
        if (plant.getUtilityId() == -1) {
            std::cout << "Bad value for utility ID at record "
                      << i << std::endl;
        }
        std::string plantName = plant.getPlantName();
        if (plantName.compare("INVALID") == 0) {
            std::cout << "Bad value for plant name at record "
                      << i << std::endl;
        }
        std::string plantType = plant.getPlantType();
        if (plantType.compare("INVALID") == 0) {
            std::cout << "Bad value for plant type at record "
                      << i << std::endl;
        }
        double capacityMw = plant.getCapacityMw();
        if (capacityMw == -1) {
            std::cout << "Bad value for capacityMw at record "
                      << i << std::endl;
        }
        double peakDemandMw = plant.getPeakDemandMw();
        if (peakDemandMw == -1) {
            std::cout << "Bad value for peakDemandMw at record "
                      << i << std::endl;
        }
        double plantHoursConnectedWhileGenerating = plant.getPlantHoursConnectedWhileGenerating();
        if (plantHoursConnectedWhileGenerating == -1) {
            std::cout << "Bad value for plantHoursConnectedWhileGenerating at record "
                      << i << std::endl;
        }
        double netCapacityFavorableConditionsMw = plant.getNetCapacityFavorableConditionsMw();
        if (netCapacityFavorableConditionsMw == -1) {
            std::cout << "Bad value for netCapacityFavorableConditionsMw at record "
                      << i << std::endl;
        }
        double netCapacityAdverseConditionsMw = plant.getNetCapacityAdverseConditionsMw();
        if (netCapacityAdverseConditionsMw == -1) {
            std::cout << "Bad value for netCapacityAdverseConditionsMw at record "
                      << i << std::endl;
        }
        double netGenerationMwh = plant.getNetGenerationMwh();
        if (netGenerationMwh == -1) {
            std::cout << "Bad value for netGenerationMwh at record "
                      << i << std::endl;
        }
        i += 1;
    }
    std::cout << "All records valid" << std::endl;
}

/**
 * Plant object tests.
 */
void PlantTest() {
    Plant testObject = Plant();
    // Test setters and getters
    testObject.setRowId(1);
    assert (testObject.getRowId() == 1);
    testObject.setUtilityId(1);
    assert (testObject.getUtilityId() == 1);
    testObject.setPlantName("TestPlant");
    assert (testObject.getPlantName() == "TestPlant");
    testObject.setPlantType("TestType");
    assert (testObject.getPlantType() == "TestType");
    testObject.setInstallationYear(2022.0);
    assert (testObject.getInstallationYear() == 2022.0);
    testObject.setCapacityMw(100.0);
    assert (testObject.getCapacityMw() == 100.0);
    testObject.setPeakDemandMw(95.0);
    assert (testObject.getPeakDemandMw() == 95.0);
    testObject.setPlantHoursConnectedWhileGenerating(1000.0);
    assert (testObject.getPlantHoursConnectedWhileGenerating() == 1000.0);
    testObject.setNetCapacityFavorableConditionsMw(100.0);
    assert (testObject.getNetCapacityFavorableConditionsMw() == 100.0);
    testObject.setNetCapacityAdverseConditionsMw(50.0);
    assert (testObject.getNetCapacityAdverseConditionsMw() == 50.0);
    testObject.setNetGenerationMwh(1000.0);
    assert (testObject.getNetGenerationMwh() == 1000.0);
    // Test initialization (and getters)
    Plant testObject2 = Plant(5, 6, "TestPlant2",
                              "Storage",
                              2000.0, 80.0, 70.0, 5000.0,
                              100.0, 80.0, 1000.0);
    assert (testObject2.getRowId() == 5);
    assert (testObject2.getUtilityId() == 6);
    assert (testObject2.getPlantName() == "TestPlant2");
    assert (testObject2.getPlantType() == "Storage");
    assert (testObject2.getInstallationYear() == 2000.0);
    assert (testObject2.getCapacityMw() == 80.0);
    assert (testObject2.getPeakDemandMw() == 70.0);
    assert (testObject2.getPlantHoursConnectedWhileGenerating() == 5000.0);
    assert (testObject2.getNetCapacityFavorableConditionsMw() == 100.0);
    assert (testObject2.getNetCapacityAdverseConditionsMw() == 80.0);
    assert (testObject2.getNetGenerationMwh() == 1000.0);

    std::cout << "Setters/Getters function as intended" << std::endl;
}

#endif // Plant_H
