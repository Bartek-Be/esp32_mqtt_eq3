
idf_component_register(
    SRCS 
        "eq3_bootwifi.c"
        "eq3_gap.c"
        "eq3_main.c"
        "eq3_timer.c"
        "eq3_wifi.c"
        "eq3_ha_discovery.c"
        "../components/mongoose/mongoose.c"
    INCLUDE_DIRS 
        "."
)
