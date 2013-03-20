//
//  sniff.h
//  wifisonifi
//
//  Created by Jonas Gruska on 18.3.2013.
//
//

#ifndef __wifisonifi__sniff__
#define __wifisonifi__sniff__

#include <iostream>

#include "sniff.h"
#include <pcap.h>
#include <string>

class sniff {
public:
    const u_char * packet;
    std::string content;
    std::vector<std::string> elems;

    struct stuff {
        bpf_u_int32 len;
        u_char content;
    } original, copy;
    bool lock;
    //string content;
    
    pcap_t *descr = NULL;
    struct pcap_pkthdr header;
    
    void setup() {
        char errbuf[ PCAP_ERRBUF_SIZE], *device=NULL;
        memset(errbuf,0,PCAP_ERRBUF_SIZE);
        
        descr = pcap_open_live("en1", 1024, 1, 20, errbuf);
        if (descr == NULL) {
            fprintf(stderr, "Couldn't open device %s: %s\n", "en1", errbuf);
            return(2);
        
        }
        //pcap_set_rfmon(descr, 1);
    }
    
    void get_packet() {
        packet = pcap_next(descr, &header);
        for (u_char const* it=packet; it != packet + header.len; ++it)
        {
            if (isprint(*it)) content += *it;
            else content += " ";
            if (content.size() > 121) {
                if (elems.size() > 42) elems.erase(elems.begin());
                elems.push_back(content);
                content = "";
            }
        }
    }
};

#endif /* defined(__wifisonifi__sniff__) */
