/* ABS ECU with services like Vehicle speed, Wheel pressure, brake status, 
and with max brake pressure that can be set and the apply brake method.
*/

// General C++ Headers
#include<iostream>
#include<iomanip>
#include<sstream>

//SOMEIP specific headers

#include<vsomeip/vsomeip.hpp>

//Declaration of the Service, event groups, events and the methods with the respective IDs.

#define ABS_Brake_service 0x3000 //ABS_Brake_service 
#define ABS_Brake_WO_ESP_instance 0x3001  //Instance of ABS_Brake_service without ESP functionality.
#define ABS_event_group 0x8200 //Event group of ABS
#define ABS_event_vehicle_speed 0x8021 //Vehicle speed event 
#define ABS_event_brake_status 0x8022 //Brake status event
#define ABS_event_wheel_pressure 0x8023 //wheel status event , an array data
#define ABS_Apply_Brake_method 0x5000  // ABS brake method


//Declaration of the ABS app

std::shared_ptr<vsomeip :: application> abs_app;
std::shared_ptr<vsomeip::payload> abs_brake_data;



//itsgroup.insert(ABS_event_group)

//Main function
int main() {
      abs_app= vsomeip::runtime::get()->create_application("ABS");
      std::set<vsomeip::eventgroup_t> its_groups;
      const vsomeip::byte_t its_data[]={0x90};
      abs_brake_data= vsomeip::runtime::get()->create_payload();
      abs_brake_data->set_data(its_data,sizeof(its_data));
      its_groups.insert(ABS_event_group);
      abs_app->init();
      abs_app->offer_service(ABS_Brake_service, ABS_Brake_WO_ESP_instance);
      std:: cout << "Service is offered"<<std::endl;
      abs_app->offer_event(ABS_Brake_service,ABS_Brake_WO_ESP_instance,ABS_event_brake_status,its_groups,vsomeip_v3::event_type_e::ET_EVENT,std::chrono::milliseconds(1000));
      abs_app->notify(ABS_Brake_service,ABS_Brake_WO_ESP_instance,ABS_event_brake_status,abs_brake_data);
      abs_app->start();












}
