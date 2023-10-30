#include "Component.h"
#include "MHRD.h"

#define KY021_PIN 3
#define SEESAW_VOLUME 0.01// liter
#define FUNNEL_AREA 0.5// m^2

class KY021 : public Component{
    private:
        bool seesaw_state;

        float info;

        long last_tip;

        MHRD* rainmeter;

    public:
        KY021();
        ~KY021();
        float getRainfall() const;
        void print() const override;
        void read() override;
        void start() override;
};