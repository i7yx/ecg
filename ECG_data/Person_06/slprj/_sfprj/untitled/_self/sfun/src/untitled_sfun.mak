# ------------------- Required for MSVC nmake ---------------------------------
# This file should be included at the top of a MAKEFILE as follows:


CPU = AMD64

MODEL     = untitled
TARGET      = sfun
MODULE_SRCS   = c4_untitled.c half_type.c
MODEL_SRC  = untitled_sfun.c
MODEL_REG = untitled_sfun_registry.c
MAKEFILE    = untitled_sfun.mak
MATLAB_ROOT  = F:\matlab
BUILDARGS   =

#--------------------------- Tool Specifications ------------------------------
#
#
MSVC_ROOT1 = $(MSDEVDIR:SharedIDE=vc)
MSVC_ROOT2 = $(MSVC_ROOT1:SHAREDIDE=vc)
MSVC_ROOT  = $(MSVC_ROOT2:sharedide=vc)

# Compiler tool locations, CC, LD, LIBCMD:
CC     = cl.exe
LD     = link.exe
LIBCMD = lib.exe
#------------------------------ Include/Lib Path ------------------------------

USER_INCLUDES   =  /I "F:\ECG_analysis\ECG_data\ecg-id-database-1.0.0\Person_06" /I "F:\ECG_analysis\ECG_m"
AUX_INCLUDES   = 
MLSLSF_INCLUDES = \
    /I "F:\matlab\extern\include" \
    /I "F:\matlab\simulink\include" \
    /I "F:\matlab\simulink\include\sf_runtime" \
    /I "F:\matlab\stateflow\c\mex\include" \
    /I "F:\matlab\rtw\c\src" \
    /I "F:\ECG_analysis\ECG_data\ecg-id-database-1.0.0\Person_06\slprj\_sfprj\untitled\_self\sfun\src" 

COMPILER_INCLUDES = /I "$(MSVC_ROOT)\include"

THIRD_PARTY_INCLUDES   =  /I "F:\ECG_analysis\ECG_data\ecg-id-database-1.0.0\Person_06\slprj\_sfprj\untitled\_self\sfun\src\CXSparse\Include" /I "F:\ECG_analysis\ECG_data\ecg-id-database-1.0.0\Person_06\slprj\_sfprj\untitled\_self\sfun\src\CXSparse\SuiteSparse_config" /I "F:\ECG_analysis\ECG_data\ecg-id-database-1.0.0\Person_06\slprj\_sfprj\untitled\_self\sfun\src\CXSparse\CXSparseSupport"
INCLUDE_PATH = $(USER_INCLUDES) $(AUX_INCLUDES) $(MLSLSF_INCLUDES)\
 $(THIRD_PARTY_INCLUDES)
LIB_PATH     = "$(MSVC_ROOT)\lib"

CFLAGS = /c /Zp8 /GR /W3 /EHs /D_CRT_SECURE_NO_DEPRECATE /D_SCL_SECURE_NO_DEPRECATE /D_SECURE_SCL=0 /DMX_COMPAT_64 /DMATLAB_MEXCMD_RELEASE=R2018a /DMATLAB_MEX_FILE /nologo /MD  
LDFLAGS = /nologo /dll /MANIFEST /OPT:NOREF /export:mexFunction /export:mexfilerequiredapiversion  
#----------------------------- Source Files -----------------------------------

REQ_SRCS  =  $(MODEL_SRC) $(MODEL_REG) $(MODULE_SRCS)

USER_OBJS =

AUX_ABS_OBJS =

THIRD_PARTY_OBJS     = \
     "c_mexapi_version.obj" \
     "cs_ri_bundle.obj" \
     "cs_ci_bundle.obj" \
     "solve_from_lu.obj" \
     "solve_from_qr.obj" \
     "makeCXSparseMatrix.obj" \
     "unpackCXStruct.obj" \

REQ_OBJS = $(REQ_SRCS:.cpp=.obj)
REQ_OBJS2 = $(REQ_OBJS:.c=.obj)
OBJS = $(REQ_OBJS2) $(USER_OBJS) $(AUX_ABS_OBJS) $(THIRD_PARTY_OBJS)
OBJLIST_FILE = untitled_sfun.mol
SFCLIB = 
AUX_LNK_OBJS =     
USER_LIBS = 
#--------------------------------- Rules --------------------------------------

MEX_FILE_NAME_WO_EXT = $(MODEL)_$(TARGET)
MEX_FILE_NAME = $(MEX_FILE_NAME_WO_EXT).mexw64
MEX_FILE_CSF =
all : $(MEX_FILE_NAME) $(MEX_FILE_CSF)

$(MEX_FILE_NAME) : $(MAKEFILE) $(OBJS) $(SFCLIB) $(AUX_LNK_OBJS) $(USER_LIBS) $(THIRD_PARTY_LIBS)
 @echo ### Linking ...
 $(LD) $(LDFLAGS) /OUT:$(MEX_FILE_NAME) /map:"$(MEX_FILE_NAME_WO_EXT).map"\
  $(USER_LIBS) $(SFCLIB) $(AUX_LNK_OBJS)\
  $(DSP_LIBS) $(THIRD_PARTY_LIBS)\
  @$(OBJLIST_FILE)
	@echo ### Created $@

.c.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"

.cpp.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"


c_mexapi_version.obj :  "F:\matlab\extern\version\c_mexapi_version.c"
	@echo ### Compiling "F:\matlab\extern\version\c_mexapi_version.c"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "F:\matlab\extern\version\c_mexapi_version.c"
cs_ri_bundle.obj :  "F:\ECG_analysis\ECG_data\ecg-id-database-1.0.0\Person_06\slprj\_sfprj\untitled\_self\sfun\src\CXSparse\Source\cs_ri_bundle.c"
	@echo ### Compiling "F:\ECG_analysis\ECG_data\ecg-id-database-1.0.0\Person_06\slprj\_sfprj\untitled\_self\sfun\src\CXSparse\Source\cs_ri_bundle.c"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "F:\ECG_analysis\ECG_data\ecg-id-database-1.0.0\Person_06\slprj\_sfprj\untitled\_self\sfun\src\CXSparse\Source\cs_ri_bundle.c"
cs_ci_bundle.obj :  "F:\ECG_analysis\ECG_data\ecg-id-database-1.0.0\Person_06\slprj\_sfprj\untitled\_self\sfun\src\CXSparse\Source\cs_ci_bundle.c"
	@echo ### Compiling "F:\ECG_analysis\ECG_data\ecg-id-database-1.0.0\Person_06\slprj\_sfprj\untitled\_self\sfun\src\CXSparse\Source\cs_ci_bundle.c"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "F:\ECG_analysis\ECG_data\ecg-id-database-1.0.0\Person_06\slprj\_sfprj\untitled\_self\sfun\src\CXSparse\Source\cs_ci_bundle.c"
solve_from_lu.obj :  "F:\ECG_analysis\ECG_data\ecg-id-database-1.0.0\Person_06\slprj\_sfprj\untitled\_self\sfun\src\CXSparse\CXSparseSupport\solve_from_lu.c"
	@echo ### Compiling "F:\ECG_analysis\ECG_data\ecg-id-database-1.0.0\Person_06\slprj\_sfprj\untitled\_self\sfun\src\CXSparse\CXSparseSupport\solve_from_lu.c"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "F:\ECG_analysis\ECG_data\ecg-id-database-1.0.0\Person_06\slprj\_sfprj\untitled\_self\sfun\src\CXSparse\CXSparseSupport\solve_from_lu.c"
solve_from_qr.obj :  "F:\ECG_analysis\ECG_data\ecg-id-database-1.0.0\Person_06\slprj\_sfprj\untitled\_self\sfun\src\CXSparse\CXSparseSupport\solve_from_qr.c"
	@echo ### Compiling "F:\ECG_analysis\ECG_data\ecg-id-database-1.0.0\Person_06\slprj\_sfprj\untitled\_self\sfun\src\CXSparse\CXSparseSupport\solve_from_qr.c"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "F:\ECG_analysis\ECG_data\ecg-id-database-1.0.0\Person_06\slprj\_sfprj\untitled\_self\sfun\src\CXSparse\CXSparseSupport\solve_from_qr.c"
makeCXSparseMatrix.obj :  "F:\ECG_analysis\ECG_data\ecg-id-database-1.0.0\Person_06\slprj\_sfprj\untitled\_self\sfun\src\CXSparse\CXSparseSupport\makeCXSparseMatrix.c"
	@echo ### Compiling "F:\ECG_analysis\ECG_data\ecg-id-database-1.0.0\Person_06\slprj\_sfprj\untitled\_self\sfun\src\CXSparse\CXSparseSupport\makeCXSparseMatrix.c"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "F:\ECG_analysis\ECG_data\ecg-id-database-1.0.0\Person_06\slprj\_sfprj\untitled\_self\sfun\src\CXSparse\CXSparseSupport\makeCXSparseMatrix.c"
unpackCXStruct.obj :  "F:\ECG_analysis\ECG_data\ecg-id-database-1.0.0\Person_06\slprj\_sfprj\untitled\_self\sfun\src\CXSparse\CXSparseSupport\unpackCXStruct.c"
	@echo ### Compiling "F:\ECG_analysis\ECG_data\ecg-id-database-1.0.0\Person_06\slprj\_sfprj\untitled\_self\sfun\src\CXSparse\CXSparseSupport\unpackCXStruct.c"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "F:\ECG_analysis\ECG_data\ecg-id-database-1.0.0\Person_06\slprj\_sfprj\untitled\_self\sfun\src\CXSparse\CXSparseSupport\unpackCXStruct.c"
