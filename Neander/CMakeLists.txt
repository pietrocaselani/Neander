cmake_minimum_required(VERSION 3.3)
project(Neander)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        IInstruction.h
        IProcessor.h
        Accumulator.cpp Accumulator.h
        Memory.cpp Memory.h
        ProgramCounter.cpp ProgramCounter.h
        NeanderProcessor.cpp NeanderProcessor.h
        NOP.cpp NOP.h
        STA.cpp STA.h
        LDA.cpp LDA.h
        HLT.cpp HLT.h
        NOT.cpp NOT.h
        OR.cpp OR.h
        AND.cpp AND.h
        ADD.cpp ADD.h
        JMP.cpp JMP.h
        JN.cpp JN.h
        JZ.cpp JZ.h
)

add_library(Neander SHARED ${SOURCE_FILES})

set_target_properties(Neander PROPERTIES
        OUTPUT_NAME neander
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)