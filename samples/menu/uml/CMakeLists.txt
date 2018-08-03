message("Generating buy_menu diagram")

execute_process(COMMAND plantuml ${CMAKE_CURRENT_SOURCE_DIR}/buy_menu.uml -o ${${PROJ_MAIN_NAME}_PATH_DIAG})
