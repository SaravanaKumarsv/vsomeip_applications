#include<iostream>
#include<iomanip>
#include<vsomeip/vsomeip.hpp>
#include <sstream>
#include<string>
#include<vsomeip/primitive_types.hpp>

std::shared_ptr <vsomeip ::application> VCU_app;

#define ABS_Brake_service 0x3000 //ABS_Brake_service 
#define ABS_Brake_WO_ESP_instance 0x3001  //Instance of ABS_Brake_service without ESP functionality.
#define ABS_event_group 0x8200 //Event group of ABS
#define ABS_event_vehicle_speed 0x8021 //Vehicle speed event 
#define ABS_event_brake_status 0x8022 //Brake status event
#define ABS_event_wheel_pressure 0x8023 //wheel status event , an array data
#define ABS_Apply_Brake_method 0x5000  // ABS brake method

int counter =0;
bool unregister_status = true;

std::string to_hex(unsigned short decimal, uint8_t width){
    std::stringstream ss;
    ss<<"0x"<<std::setw(width) << std:: setfill('0')<<std::hex<< decimal;
    return ss.str();
}


void service_available(vsomeip::service_t service,vsomeip::instance_t instance,bool is_available){
    std::cout<<"\t Service [ "<< std::setw(4) 
    << std::setfill('0')
    <<std::hex << service << "." 
    << instance <<"] is "<<(is_available?"is available": "NOT available.")<< std::endl;

}

/*void sub_status(vsomeip::client_t client_id,vsome::uid_t uid , vsomeip::gid_t gid , bool subs_avail){


}*/
void on_message(const std::shared_ptr<vsomeip::message> &_response){
    std::stringstream on_message;
    std::stringstream its_message;
   if(counter<10 && unregister_status){
    counter++;
        std::cout<<counter<<std::endl;
    its_message << "CLIENT: received a notification for event ["
            << std::setw(4) << std::setfill('0') << std::hex
            << _response->get_service() << "."
            << std::setw(4) << std::setfill('0') << std::hex
            << _response->get_instance() << "."
            << std::setw(4) << std::setfill('0') << std::hex
            << _response->get_method() << "] to Client/Session ["
            << std::setw(4) << std::setfill('0') << std::hex
            << _response->get_client() << "/"
            << std::setw(4) << std::setfill('0') << std::hex
            << _response->get_session()
            << "] = ";
    std::shared_ptr<vsomeip::payload> its_payload = _response->get_payload();
    its_message << "(" << std::dec << its_payload->get_length() << ") ";
    for (uint32_t i = 0; i < its_payload->get_length(); ++i)
        its_message << std::hex << std::setw(2) << std::setfill('0')
            << (int) its_payload->get_data()[i] << " ";
    std::cout << its_message.str() << std::endl;

    //std::stringstream new_message;
  /*  
    vsomeip::client_t client_id = to_hex( _response->get_client(),4);
    vsomeip::service_t service_id= to_hex( _response->get_service(),4);
    vsomeip::instance_t instance_id= to_hex( _response->get_client(),4);
    vsomeip::event_t method_id =to_hex( _response->get_method(),4);
*/
    std::cout<<to_hex( _response->get_service(),4)<<" "<< to_hex( _response->get_instance(),4)<<" "<<to_hex( _response->get_client(),4)<<" "<<to_hex( _response->get_method(),4)<<std::endl;

  /*  
    std::cout<<"service id : "<<service_id<<int (ABS_Brake_service)<<std::endl;
    std::cout<<"instance id : "<<instance_id<<int (ABS_Brake_WO_ESP_instance)<<std::endl;
    std::cout<<"method id : "<<method_id<<int (ABS_event_brake_status)<<std::endl;
    std::cout<<"client id : "<<client_id<<int (ABS_Brake_service)<<std::endl;
    
*/
   /* if (client_i
    new_message<< "[service is "<< std::setw(4)<<std::setfill('0')<< _response->get_service()
    <<"instance is "<<std::setw(4)<<std::setw('0')<<std::hex<<_response->get_instance()
    <<"method is "<< _response->get_method() <<"is sending to client" << _response->get_client() << "at session " << _response->get_session()
    <<"the vehicle speed is ";
    std::shared_ptr<vsomeip::payload> new_payload=_response->get_payload();
    vsomeip::length_t len = _response->get_length();

    for (uint32_t i=0; i<len; i++){
        new_message<<new_payload->get_data()[i];
    }

    std::cout<<new_message.str()<<std::endl;

*/
   }
   else{
    VCU_app-> unregister_message_handler(vsomeip::ANY_SERVICE, vsomeip::ANY_INSTANCE, vsomeip::ANY_METHOD);
    std::cout<<"unregister happend"<<std::endl;
    unregister_status= false;
   }
    

}


int main() {
    VCU_app= vsomeip::runtime::get()-> create_application("VCU");
    VCU_app->init();

    std::set<vsomeip::eventgroup_t> its_groups;
    its_groups.insert(ABS_event_group);
    VCU_app->register_availability_handler(ABS_Brake_service,ABS_Brake_WO_ESP_instance,service_available);
  

    VCU_app->request_service(ABS_Brake_service,ABS_Brake_WO_ESP_instance);
    VCU_app->request_event(ABS_Brake_service,ABS_Brake_WO_ESP_instance,ABS_event_brake_status,its_groups);
    VCU_app->register_message_handler(vsomeip::ANY_SERVICE, vsomeip::ANY_INSTANCE, vsomeip::ANY_METHOD, on_message);
    VCU_app->subscribe(ABS_Brake_service,ABS_Brake_WO_ESP_instance,ABS_event_group);
    


    VCU_app->start();


}




