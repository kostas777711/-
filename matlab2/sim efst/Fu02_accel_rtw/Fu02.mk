# Copyright 1994-2002 The MathWorks, Inc.
#
# File    : accel_lcc.tmf   $Revision: 1.19 $
#
# Abstract:
#	Accelerator template makefile for building a PC-based,
#       RTW generated mex-file of Simulink model using generated C code. 
#	     LCC compiler version 2.4.
#
# 	This makefile attempts to conform to the guidelines specified in the
# 	IEEE Std 1003.2-1992 (POSIX) standard. It is designed to be used
#       with GNU Make (gmake) which is located in matlabroot/rtw/bin/win32.
#
# 	Note that this template is automatically customized by the Real-Time
#	Workshop build procedure to create "<model>.mk"
#
#       The following defines can be used to modify the behavior of the
#	build:
#
#         MEX_OPTS       - User specific mex options.
#	  OPT_OPTS       - Optimization options. Default is none. To enable 
#                          debugging specify as OPT_OPTS=-g. 
#	  USER_SRCS      - Additional user sources, such as files needed by
#			   S-functions.
#	  USER_INCLUDES  - Additional include paths
#			   (i.e. USER_INCLUDES="-Iwhere-ever -Iwhere-ever2")
#			   (For Lcc, have a '/'as file seperator before the 
#			   file name instead of a '\' . 
#			   i.e.,  d:\work\proj1/myfile.c - reqd for 'gmake')
#
#       This template makefile is designed to be used with a system target
#       file that contains 'rtwgensettings.BuildDirSuffix' see accel.tlc

#------------------------ Macros read by make_rtw ------------------------------
#
# The following macros are read by the Real-Time Workshop build procedure:
#
#  MAKECMD         - This is the command used to invoke the make utility
#  HOST            - What platform this template makefile is targeted for
#                    (i.e. PC or UNIX)
#  BUILD           - Invoke make from the Real-Time Workshop build procedure
#                    (yes/no)?
#  SYS_TARGET_FILE - Name of system target file.

MAKECMD         = "%MATLAB%\rtw\bin\win32\gmake"
HOST            = PC
BUILD           = yes
SYS_TARGET_FILE = accel.tlc

#---------------------- Tokens expanded by make_rtw ----------------------------
#
# The following tokens, when wrapped with "|>" and "|<" are expanded by the
# Real-Time Workshop build procedure.
#
#  MODEL_NAME      - Name of the Simulink block diagram
#  MODEL_MODULES   - Any additional generated source modules
#  MAKEFILE_NAME   - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT     - Path to were MATLAB is installed.
#  MATLAB_BIN      - Path to MATLAB executable.
#  S_FUNCTIONS     - List of S-functions.
#  S_FUNCTIONS_LIB - List of S-functions libraries to link.
#  SOLVER          - Solver source file name
#  NUMST           - Number of sample times
#  TID01EQ         - yes (1) or no (0): Are sampling rates of continuous task
#                    (tid=0) and 1st discrete task equal.
#  NCSTATES        - Number of continuous states
#  BUILDARGS       - Options passed in at the command line.

MODEL           = Fu02
MODULES         = Fu02_acc_data.c 
MAKEFILE        = Fu02.mk
MATLAB_ROOT     = C:\MATLAB6p5
MATLAB_BIN      = C:\MATLAB6p5\bin\win32
S_FUNCTIONS     = scominhshape.c
S_FUNCTIONS_LIB = 
SOLVER          = ode45.c
NUMST           = 2
TID01EQ         = 0
NCSTATES        = 2
MEM_ALLOC       = RT_STATIC
BUILDARGS       = ADD_MDL_NAME_TO_GLOBALS=1

#--------------------------- Tool Specifications -------------------------------

LCC = $(MATLAB_ROOT)\sys\lcc
include $(MATLAB_ROOT)\rtw\c\tools\lcctools.mak

MEX = $(MATLAB_BIN)\mex.bat
CC  = $(MATLAB_BIN)\mex.bat -c

#------------------------------ Include Path -----------------------------------

# Additional includes

ADD_INCLUDES = \
	-Ic:\matlab6p5\rtw\c\libsrc \
	-Ic:\matlab6p5\toolbox\commblks\sim\export\include \
	-Ic:\matlab6p5\toolbox\commblks\sim\sfun\include \
	-Ic:\matlab6p5\toolbox\commblks\sim\src\include \
	-Ic:\matlab6p5\toolbox\commblks\sim\src\legacy\include \
	-Ic:\matlab6p5\toolbox\comm\commshr\export\include \
	-Ic:\matlab6p5\toolbox\comm\commshr\src\include \
	-Ic:\matlab6p5\toolbox\dspblks\src\sim \
	-Ic:\matlab6p5\toolbox\dspblks\include \
	-Ic:\matlab6p5\toolbox\dspblks\src\v2 \


# see MATLAB_INCLUES and COMPILER_INCLUDES from lcctool.mak

INCLUDES = -I. -I.. $(MATLAB_INCLUDES) $(ADD_INCLUDES) \
           $(COMPILER_INCLUDES) $(USER_INCLUDES)

#------------------------ C and MEX optimization options -----------------------
MEX_OPTS  =
OPT_OPTS  = $(DEFAULT_OPT_OPTS)
MEX_OPT_OPTS = $(OPT_OPTS)    # passed to 'mex -c'

ifeq "$(MEX_OPTS)" "-g"
MEX_OPT_OPTS =
endif

#-------------------------------- Mex Options  ---------------------------------
MEX_OPT_FILE = -f $(MATLAB_BIN)\mexopts\lccopts.bat
MEX_FLAGS = $(MEX_OPT_OPTS) $(MEX_OPTS) $(MEX_OPT_FILE)

#----------------------------- Source Files -----------------------------------
USER_SRCS =

USER_OBJS       = $(USER_SRCS:.c=.obj)
LOCAL_USER_OBJS = $(notdir $(USER_OBJS))

SRCS      = $(MODEL)_acc.c $(MODULES)
OBJS      = $(SRCS:.c=.obj) $(USER_OBJS)
LINK_OBJS = $(SRCS:.c=.obj) $(LOCAL_USER_OBJS)

#------------------------- Additional Libraries -------------------------------

LIBS =

ifeq ($(OPT_OPTS),$(DEFAULT_OPT_OPTS))
LIBS += $(MATLAB_ROOT)\toolbox\dspblks\lib\win32\dsp_rt_rtwsfcn_lcc.lib
else
LIBS += dsp_rt.lib
endif

ifeq ($(OPT_OPTS),$(DEFAULT_OPT_OPTS))
LIBS += $(MATLAB_ROOT)\rtw\c\lib\win32\rtwlib_rtwsfcn_lcc.lib
else
LIBS += rtwlib.lib
endif



LIBUT = $(MATLAB_ROOT)\rtw\c\lib\win32\libut_lcc.lib
LIBS += $(LIBUT)


PROGRAM = ../$(MODEL)_acc.dll

#--------------------------------- Rules --------------------------------------

$(PROGRAM) : $(OBJS) $(LIBS)
	@echo ### Linking ...
	$(MEX) $(MEX_FLAGS) -outdir .. $(LINK_OBJS) $(LIBS) $(S_FUNCTIONS_LIB)
	@echo ### Created mex file: $(MODEL)_acc.dll

%.obj : %.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : ../%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\rtw\c\libsrc/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\comm\commshr\src\legacy/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\commblks\sim\sfun/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\commblks\sim\src\legacy/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dspacf/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dspallpole/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dspbiquad/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dspburg/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dspchol/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dspconvcorr/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dspendian/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dspeph/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dspfbsub/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dspfft/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dspfilterbank/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dspfir/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dspfirdn/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dspflip/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dspgivensrot/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dsphist/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dspic/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dspiir/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dspinterp/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dspisfinite/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dspldl/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dsplevdurb/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dsplsp2poly/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dsplu/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dspmmult/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dsppad/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dsppinv/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dsppoly2lsf/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dsppolyval/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dspqrdc/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dspqsrt/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dsprandsrc/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dsprebuff/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dspsvd/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dspunwrap/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dspupfir/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dspupfirdn/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dspvfdly/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\rtw\dspblks\c\dspwindow/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\dspblks\src\v4/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\dspblks\src\v3/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

%.obj : c:\matlab6p5\toolbox\dspblks\src\v2/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<



%.obj : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(MEX_FLAGS) $(INCLUDES) $<

# Libraries:



MODULES_dsp_rt = \
          acf_fd_c_rt.obj \
          acf_fd_d_rt.obj \
          acf_fd_r_rt.obj \
          acf_fd_z_rt.obj \
          acf_fft_interleave_zpad_d_rt.obj \
          acf_fft_interleave_zpad_r_rt.obj \
          acf_td_c_rt.obj \
          acf_td_d_rt.obj \
          acf_td_r_rt.obj \
          acf_td_z_rt.obj \
          copy_and_zero_pad_cc_nchan_rt.obj \
          copy_and_zero_pad_zz_nchan_rt.obj \
          allpole_df_a0scale_cc_rt.obj \
          allpole_df_a0scale_cr_rt.obj \
          allpole_df_a0scale_dd_rt.obj \
          allpole_df_a0scale_dz_rt.obj \
          allpole_df_a0scale_rc_rt.obj \
          allpole_df_a0scale_rr_rt.obj \
          allpole_df_a0scale_zd_rt.obj \
          allpole_df_a0scale_zz_rt.obj \
          allpole_df_cc_rt.obj \
          allpole_df_cr_rt.obj \
          allpole_df_dd_rt.obj \
          allpole_df_dz_rt.obj \
          allpole_df_rc_rt.obj \
          allpole_df_rr_rt.obj \
          allpole_df_zd_rt.obj \
          allpole_df_zz_rt.obj \
          allpole_lat_cc_rt.obj \
          allpole_lat_cr_rt.obj \
          allpole_lat_dd_rt.obj \
          allpole_lat_dz_rt.obj \
          allpole_lat_rc_rt.obj \
          allpole_lat_rr_rt.obj \
          allpole_lat_zd_rt.obj \
          allpole_lat_zz_rt.obj \
          allpole_tdf_a0scale_cc_rt.obj \
          allpole_tdf_a0scale_cr_rt.obj \
          allpole_tdf_a0scale_dd_rt.obj \
          allpole_tdf_a0scale_dz_rt.obj \
          allpole_tdf_a0scale_rc_rt.obj \
          allpole_tdf_a0scale_rr_rt.obj \
          allpole_tdf_a0scale_zd_rt.obj \
          allpole_tdf_a0scale_zz_rt.obj \
          allpole_tdf_cc_rt.obj \
          allpole_tdf_cr_rt.obj \
          allpole_tdf_dd_rt.obj \
          allpole_tdf_dz_rt.obj \
          allpole_tdf_rc_rt.obj \
          allpole_tdf_rr_rt.obj \
          allpole_tdf_zd_rt.obj \
          allpole_tdf_zz_rt.obj \
          bq4_df2t_1fpf_1sos_cc_rt.obj \
          bq4_df2t_1fpf_1sos_cr_rt.obj \
          bq4_df2t_1fpf_1sos_dd_rt.obj \
          bq4_df2t_1fpf_1sos_dz_rt.obj \
          bq4_df2t_1fpf_1sos_rc_rt.obj \
          bq4_df2t_1fpf_1sos_rr_rt.obj \
          bq4_df2t_1fpf_1sos_zd_rt.obj \
          bq4_df2t_1fpf_1sos_zz_rt.obj \
          bq4_df2t_1fpf_nsos_cc_rt.obj \
          bq4_df2t_1fpf_nsos_cr_rt.obj \
          bq4_df2t_1fpf_nsos_dd_rt.obj \
          bq4_df2t_1fpf_nsos_dz_rt.obj \
          bq4_df2t_1fpf_nsos_rc_rt.obj \
          bq4_df2t_1fpf_nsos_rr_rt.obj \
          bq4_df2t_1fpf_nsos_zd_rt.obj \
          bq4_df2t_1fpf_nsos_zz_rt.obj \
          bq5_df2t_1fpf_1sos_cc_rt.obj \
          bq5_df2t_1fpf_1sos_cr_rt.obj \
          bq5_df2t_1fpf_1sos_dd_rt.obj \
          bq5_df2t_1fpf_1sos_dz_rt.obj \
          bq5_df2t_1fpf_1sos_rc_rt.obj \
          bq5_df2t_1fpf_1sos_rr_rt.obj \
          bq5_df2t_1fpf_1sos_zd_rt.obj \
          bq5_df2t_1fpf_1sos_zz_rt.obj \
          bq5_df2t_1fpf_nsos_cc_rt.obj \
          bq5_df2t_1fpf_nsos_cr_rt.obj \
          bq5_df2t_1fpf_nsos_dd_rt.obj \
          bq5_df2t_1fpf_nsos_dz_rt.obj \
          bq5_df2t_1fpf_nsos_rc_rt.obj \
          bq5_df2t_1fpf_nsos_rr_rt.obj \
          bq5_df2t_1fpf_nsos_zd_rt.obj \
          bq5_df2t_1fpf_nsos_zz_rt.obj \
          bq6_df2t_1fpf_1sos_cc_rt.obj \
          bq6_df2t_1fpf_1sos_cr_rt.obj \
          bq6_df2t_1fpf_1sos_dd_rt.obj \
          bq6_df2t_1fpf_1sos_dz_rt.obj \
          bq6_df2t_1fpf_1sos_rc_rt.obj \
          bq6_df2t_1fpf_1sos_rr_rt.obj \
          bq6_df2t_1fpf_1sos_zd_rt.obj \
          bq6_df2t_1fpf_1sos_zz_rt.obj \
          bq6_df2t_1fpf_nsos_cc_rt.obj \
          bq6_df2t_1fpf_nsos_cr_rt.obj \
          bq6_df2t_1fpf_nsos_dd_rt.obj \
          bq6_df2t_1fpf_nsos_dz_rt.obj \
          bq6_df2t_1fpf_nsos_rc_rt.obj \
          bq6_df2t_1fpf_nsos_rr_rt.obj \
          bq6_df2t_1fpf_nsos_zd_rt.obj \
          bq6_df2t_1fpf_nsos_zz_rt.obj \
          burg_a_c_rt.obj \
          burg_a_d_rt.obj \
          burg_a_r_rt.obj \
          burg_a_z_rt.obj \
          burg_ak_c_rt.obj \
          burg_ak_d_rt.obj \
          burg_ak_r_rt.obj \
          burg_ak_z_rt.obj \
          burg_k_c_rt.obj \
          burg_k_d_rt.obj \
          burg_k_r_rt.obj \
          burg_k_z_rt.obj \
          chol_c_rt.obj \
          chol_d_rt.obj \
          chol_r_rt.obj \
          chol_z_rt.obj \
          conv_td_cc_rt.obj \
          conv_td_dd_rt.obj \
          conv_td_dz_rt.obj \
          conv_td_rc_rt.obj \
          conv_td_rr_rt.obj \
          conv_td_zz_rt.obj \
          copy_and_zpad_cc_rt.obj \
          copy_and_zpad_dz_rt.obj \
          copy_and_zpad_rc_rt.obj \
          copy_and_zpad_zz_rt.obj \
          corr_td_cc_rt.obj \
          corr_td_cr_rt.obj \
          corr_td_dd_rt.obj \
          corr_td_dz_rt.obj \
          corr_td_rc_rt.obj \
          corr_td_rr_rt.obj \
          corr_td_zd_rt.obj \
          corr_td_zz_rt.obj \
          is_little_endian_rt.obj \
          eph_zc_fcn_rt.obj \
          bsub_nu_cc_c_rt.obj \
          bsub_nu_cr_c_rt.obj \
          bsub_nu_dd_d_rt.obj \
          bsub_nu_dz_z_rt.obj \
          bsub_nu_rc_c_rt.obj \
          bsub_nu_rr_r_rt.obj \
          bsub_nu_zd_z_rt.obj \
          bsub_nu_zz_z_rt.obj \
          bsub_u_cc_c_rt.obj \
          bsub_u_cr_c_rt.obj \
          bsub_u_dd_d_rt.obj \
          bsub_u_dz_z_rt.obj \
          bsub_u_rc_c_rt.obj \
          bsub_u_rr_r_rt.obj \
          bsub_u_zd_z_rt.obj \
          bsub_u_zz_z_rt.obj \
          fsub_nu_cc_c_rt.obj \
          fsub_nu_cr_c_rt.obj \
          fsub_nu_dd_d_rt.obj \
          fsub_nu_dz_z_rt.obj \
          fsub_nu_rc_c_rt.obj \
          fsub_nu_rr_r_rt.obj \
          fsub_nu_zd_z_rt.obj \
          fsub_nu_zz_z_rt.obj \
          fsub_u_cc_c_rt.obj \
          fsub_u_cr_c_rt.obj \
          fsub_u_dd_d_rt.obj \
          fsub_u_dz_z_rt.obj \
          fsub_u_rc_c_rt.obj \
          fsub_u_rr_r_rt.obj \
          fsub_u_zd_z_rt.obj \
          fsub_u_zz_z_rt.obj \
          dspfft_rt.obj \
          dspifft_rt.obj \
          fft_dbllen_tbl_c_rt.obj \
          fft_dbllen_tbl_z_rt.obj \
          fft_dbllen_trig_c_rt.obj \
          fft_dbllen_trig_z_rt.obj \
          fft_dblsig_br_c_rt.obj \
          fft_dblsig_br_z_rt.obj \
          fft_dblsig_c_rt.obj \
          fft_dblsig_z_rt.obj \
          fft_interleave_br_d_rt.obj \
          fft_interleave_br_r_rt.obj \
          fft_interleave_d_rt.obj \
          fft_interleave_r_rt.obj \
          fft_r2br_c_oop_rt.obj \
          fft_r2br_c_rt.obj \
          fft_r2br_dz_oop_rt.obj \
          fft_r2br_rc_oop_rt.obj \
          fft_r2br_z_oop_rt.obj \
          fft_r2br_z_rt.obj \
          fft_r2dif_tblm_c_rt.obj \
          fft_r2dif_tblm_z_rt.obj \
          fft_r2dif_tbls_c_rt.obj \
          fft_r2dif_tbls_z_rt.obj \
          fft_r2dif_trig_c_rt.obj \
          fft_r2dif_trig_z_rt.obj \
          fft_r2dit_tblm_c_rt.obj \
          fft_r2dit_tblm_z_rt.obj \
          fft_r2dit_tbls_c_rt.obj \
          fft_r2dit_tbls_z_rt.obj \
          fft_r2dit_trig_c_rt.obj \
          fft_r2dit_trig_z_rt.obj \
          fft_scaledata_dd_rt.obj \
          fft_scaledata_dz_rt.obj \
          fft_scaledata_rc_rt.obj \
          fft_scaledata_rr_rt.obj \
          ifft_addcssignals_c_c_oop_rt.obj \
          ifft_addcssignals_c_cbr_oop_rt.obj \
          ifft_addcssignals_d_z_oop_rt.obj \
          ifft_addcssignals_d_zbr_oop_rt.obj \
          ifft_addcssignals_r_c_oop_rt.obj \
          ifft_addcssignals_r_cbr_oop_rt.obj \
          ifft_addcssignals_z_z_oop_rt.obj \
          ifft_addcssignals_z_zbr_oop_rt.obj \
          ifft_dbllen_tbl_c_cbr_oop_rt.obj \
          ifft_dbllen_tbl_cbr_cbr_oop_rt.obj \
          ifft_dbllen_tbl_d_zbr_oop_rt.obj \
          ifft_dbllen_tbl_dbr_zbr_oop_rt.obj \
          ifft_dbllen_tbl_r_cbr_oop_rt.obj \
          ifft_dbllen_tbl_rbr_cbr_oop_rt.obj \
          ifft_dbllen_tbl_z_zbr_oop_rt.obj \
          ifft_dbllen_tbl_zbr_zbr_oop_rt.obj \
          ifft_dbllen_trig_c_cbr_oop_rt.obj \
          ifft_dbllen_trig_cbr_cbr_oop_rt.obj \
          ifft_dbllen_trig_d_zbr_oop_rt.obj \
          ifft_dbllen_trig_dbr_zbr_oop_rt.obj \
          ifft_dbllen_trig_r_cbr_oop_rt.obj \
          ifft_dbllen_trig_rbr_cbr_oop_rt.obj \
          ifft_dbllen_trig_z_zbr_oop_rt.obj \
          ifft_dbllen_trig_zbr_zbr_oop_rt.obj \
          ifft_deinterleave_d_d_inp_rt.obj \
          ifft_deinterleave_r_r_inp_rt.obj \
          2chabank_fr_df_cc_rt.obj \
          2chabank_fr_df_cr_rt.obj \
          2chabank_fr_df_dd_rt.obj \
          2chabank_fr_df_rr_rt.obj \
          2chabank_fr_df_zd_rt.obj \
          2chabank_fr_df_zz_rt.obj \
          2chsbank_df_cc_rt.obj \
          2chsbank_df_cr_rt.obj \
          2chsbank_df_dd_rt.obj \
          2chsbank_df_rr_rt.obj \
          2chsbank_df_zd_rt.obj \
          2chsbank_df_zz_rt.obj \
          fir_df_cc_rt.obj \
          fir_df_cr_rt.obj \
          fir_df_dd_rt.obj \
          fir_df_dz_rt.obj \
          fir_df_rc_rt.obj \
          fir_df_rr_rt.obj \
          fir_df_zd_rt.obj \
          fir_df_zz_rt.obj \
          fir_lat_cc_rt.obj \
          fir_lat_cr_rt.obj \
          fir_lat_dd_rt.obj \
          fir_lat_dz_rt.obj \
          fir_lat_rc_rt.obj \
          fir_lat_rr_rt.obj \
          fir_lat_zd_rt.obj \
          fir_lat_zz_rt.obj \
          fir_tdf_cc_rt.obj \
          fir_tdf_cr_rt.obj \
          fir_tdf_dd_rt.obj \
          fir_tdf_dz_rt.obj \
          fir_tdf_rc_rt.obj \
          fir_tdf_rr_rt.obj \
          fir_tdf_zd_rt.obj \
          fir_tdf_zz_rt.obj \
          firdn_df_dblbuf_cc_rt.obj \
          firdn_df_dblbuf_cr_rt.obj \
          firdn_df_dblbuf_dd_rt.obj \
          firdn_df_dblbuf_dz_rt.obj \
          firdn_df_dblbuf_rc_rt.obj \
          firdn_df_dblbuf_rr_rt.obj \
          firdn_df_dblbuf_zd_rt.obj \
          firdn_df_dblbuf_zz_rt.obj \
          flip_matrix_col_ip_rt.obj \
          flip_matrix_col_op_rt.obj \
          flip_matrix_row_ip_rt.obj \
          flip_matrix_row_op_rt.obj \
          flip_vector_ip_rt.obj \
          flip_vector_op_rt.obj \
          rotg_d_rt.obj \
          rotg_r_rt.obj \
          hist_c_rt.obj \
          hist_d_rt.obj \
          hist_r_rt.obj \
          hist_z_rt.obj \
          ic_copy_channel_rt.obj \
          ic_copy_matrix_rt.obj \
          ic_copy_scalar_rt.obj \
          ic_copy_vector_rt.obj \
          ic_old_copy_fcns_rt.obj \
          iir_df1_a0scale_cc_rt.obj \
          iir_df1_a0scale_cr_rt.obj \
          iir_df1_a0scale_dd_rt.obj \
          iir_df1_a0scale_dz_rt.obj \
          iir_df1_a0scale_rc_rt.obj \
          iir_df1_a0scale_rr_rt.obj \
          iir_df1_a0scale_zd_rt.obj \
          iir_df1_a0scale_zz_rt.obj \
          iir_df1_cc_rt.obj \
          iir_df1_cr_rt.obj \
          iir_df1_dd_rt.obj \
          iir_df1_dz_rt.obj \
          iir_df1_rc_rt.obj \
          iir_df1_rr_rt.obj \
          iir_df1_zd_rt.obj \
          iir_df1_zz_rt.obj \
          iir_df1t_a0scale_cc_rt.obj \
          iir_df1t_a0scale_cr_rt.obj \
          iir_df1t_a0scale_dd_rt.obj \
          iir_df1t_a0scale_dz_rt.obj \
          iir_df1t_a0scale_rc_rt.obj \
          iir_df1t_a0scale_rr_rt.obj \
          iir_df1t_a0scale_zd_rt.obj \
          iir_df1t_a0scale_zz_rt.obj \
          iir_df1t_cc_rt.obj \
          iir_df1t_cr_rt.obj \
          iir_df1t_dd_rt.obj \
          iir_df1t_dz_rt.obj \
          iir_df1t_rc_rt.obj \
          iir_df1t_rr_rt.obj \
          iir_df1t_zd_rt.obj \
          iir_df1t_zz_rt.obj \
          iir_df2_a0scale_cc_rt.obj \
          iir_df2_a0scale_cr_rt.obj \
          iir_df2_a0scale_dd_rt.obj \
          iir_df2_a0scale_dz_rt.obj \
          iir_df2_a0scale_rc_rt.obj \
          iir_df2_a0scale_rr_rt.obj \
          iir_df2_a0scale_zd_rt.obj \
          iir_df2_a0scale_zz_rt.obj \
          iir_df2_cc_rt.obj \
          iir_df2_cr_rt.obj \
          iir_df2_dd_rt.obj \
          iir_df2_dz_rt.obj \
          iir_df2_rc_rt.obj \
          iir_df2_rr_rt.obj \
          iir_df2_zd_rt.obj \
          iir_df2_zz_rt.obj \
          iir_df2t_a0scale_cc_rt.obj \
          iir_df2t_a0scale_cr_rt.obj \
          iir_df2t_a0scale_dd_rt.obj \
          iir_df2t_a0scale_dz_rt.obj \
          iir_df2t_a0scale_rc_rt.obj \
          iir_df2t_a0scale_rr_rt.obj \
          iir_df2t_a0scale_zd_rt.obj \
          iir_df2t_a0scale_zz_rt.obj \
          iir_df2t_cc_rt.obj \
          iir_df2t_cr_rt.obj \
          iir_df2t_dd_rt.obj \
          iir_df2t_dz_rt.obj \
          iir_df2t_rc_rt.obj \
          iir_df2t_rr_rt.obj \
          iir_df2t_zd_rt.obj \
          iir_df2t_zz_rt.obj \
          interp_fir_d_rt.obj \
          interp_fir_r_rt.obj \
          interp_lin_d_rt.obj \
          interp_lin_r_rt.obj \
          isfinite_d_rt.obj \
          isfinite_r_rt.obj \
          ldl_c_rt.obj \
          ldl_d_rt.obj \
          ldl_r_rt.obj \
          ldl_z_rt.obj \
          levdurb_a_c_rt.obj \
          levdurb_a_d_rt.obj \
          levdurb_a_r_rt.obj \
          levdurb_a_z_rt.obj \
          levdurb_ak_c_rt.obj \
          levdurb_ak_d_rt.obj \
          levdurb_ak_r_rt.obj \
          levdurb_ak_z_rt.obj \
          levdurb_akp_c_rt.obj \
          levdurb_akp_d_rt.obj \
          levdurb_akp_r_rt.obj \
          levdurb_akp_z_rt.obj \
          levdurb_ap_c_rt.obj \
          levdurb_ap_d_rt.obj \
          levdurb_ap_r_rt.obj \
          levdurb_ap_z_rt.obj \
          lsp2poly_evenord_d_rt.obj \
          lsp2poly_evenord_r_rt.obj \
          lsp2poly_oddord_d_rt.obj \
          lsp2poly_oddord_r_rt.obj \
          lu_c_rt.obj \
          lu_d_rt.obj \
          lu_r_rt.obj \
          lu_z_rt.obj \
          matmult_cc_rt.obj \
          matmult_cr_rt.obj \
          matmult_dd_rt.obj \
          matmult_dz_rt.obj \
          matmult_rc_rt.obj \
          matmult_rr_rt.obj \
          matmult_zd_rt.obj \
          matmult_zz_rt.obj \
          pad_cols_mixed_rt.obj \
          pad_cols_rt.obj \
          pad_copy_io_trunc_cols_rt.obj \
          pad_pre_cols_mixed_rt.obj \
          pad_pre_cols_rt.obj \
          pad_pre_rows_cols_mixed_rt.obj \
          pad_pre_rows_cols_rt.obj \
          pad_pre_rows_mixed_rt.obj \
          pad_pre_rows_rt.obj \
          pad_rows_cols_mixed_rt.obj \
          pad_rows_cols_rt.obj \
          pad_rows_mixed_rt.obj \
          pad_rows_rt.obj \
          pinv_c_rt.obj \
          pinv_d_rt.obj \
          pinv_r_rt.obj \
          pinv_z_rt.obj \
          poly2lsfn_d_rt.obj \
          poly2lsfn_r_rt.obj \
          poly2lsfr_d_rt.obj \
          poly2lsfr_r_rt.obj \
          poly2lsp_d_rt.obj \
          poly2lsp_r_rt.obj \
          polyval_cc_rt.obj \
          polyval_cr_rt.obj \
          polyval_dd_rt.obj \
          polyval_dz_rt.obj \
          polyval_rc_rt.obj \
          polyval_rr_rt.obj \
          polyval_zd_rt.obj \
          polyval_zz_rt.obj \
          qrcompqy_c_rt.obj \
          qrcompqy_d_rt.obj \
          qrcompqy_mixd_c_rt.obj \
          qrcompqy_mixd_z_rt.obj \
          qrcompqy_r_rt.obj \
          qrcompqy_z_rt.obj \
          qrdc_c_rt.obj \
          qrdc_d_rt.obj \
          qrdc_r_rt.obj \
          qrdc_z_rt.obj \
          qre_c_rt.obj \
          qre_d_rt.obj \
          qre_r_rt.obj \
          qre_z_rt.obj \
          qreslv_c_rt.obj \
          qreslv_d_rt.obj \
          qreslv_mixd_c_rt.obj \
          qreslv_mixd_z_rt.obj \
          qreslv_r_rt.obj \
          qreslv_z_rt.obj \
          srt_qid_findpivot_d_rt.obj \
          srt_qid_findpivot_r_rt.obj \
          srt_qid_partition_d_rt.obj \
          srt_qid_partition_r_rt.obj \
          srt_qkrec_c_rt.obj \
          srt_qkrec_d_rt.obj \
          srt_qkrec_r_rt.obj \
          srt_qkrec_z_rt.obj \
          randsrc_gc_c_rt.obj \
          randsrc_gc_d_rt.obj \
          randsrc_gc_r_rt.obj \
          randsrc_gc_z_rt.obj \
          randsrc_gz_c_rt.obj \
          randsrc_gz_d_rt.obj \
          randsrc_gz_r_rt.obj \
          randsrc_gz_z_rt.obj \
          randsrc_u_c_rt.obj \
          randsrc_u_d_rt.obj \
          randsrc_u_r_rt.obj \
          randsrc_u_z_rt.obj \
          randsrccreateseeds_32_rt.obj \
          randsrccreateseeds_64_rt.obj \
          randsrcinitstate_gc_32_rt.obj \
          randsrcinitstate_gc_64_rt.obj \
          randsrcinitstate_gz_rt.obj \
          randsrcinitstate_u_32_rt.obj \
          randsrcinitstate_u_64_rt.obj \
          buf_copy_frame_to_mem_OL_1ch_rt.obj \
          buf_copy_frame_to_mem_OL_rt.obj \
          buf_copy_input_to_output_1ch_rt.obj \
          buf_copy_input_to_output_rt.obj \
          buf_copy_scalar_to_mem_OL_1ch_rt.obj \
          buf_copy_scalar_to_mem_OL_rt.obj \
          buf_copy_scalar_to_mem_UL_1ch_rt.obj \
          buf_copy_scalar_to_mem_UL_rt.obj \
          buf_output_frame_1ch_rt.obj \
          buf_output_frame_rt.obj \
          buf_output_scalar_1ch_rt.obj \
          buf_output_scalar_rt.obj \
          svd_c_rt.obj \
          svd_d_rt.obj \
          svd_r_rt.obj \
          svd_z_rt.obj \
          svdcopy_rt.obj \
          unwrap_d_nrip_rt.obj \
          unwrap_d_nrop_rt.obj \
          unwrap_d_ripf_rt.obj \
          unwrap_d_rips_rt.obj \
          unwrap_d_ropf_rt.obj \
          unwrap_d_rops_rt.obj \
          unwrap_r_nrip_rt.obj \
          unwrap_r_nrop_rt.obj \
          unwrap_r_ripf_rt.obj \
          unwrap_r_rips_rt.obj \
          unwrap_r_ropf_rt.obj \
          unwrap_r_rops_rt.obj \
          upfir_copydata_rt.obj \
          upfir_df_dblbuf_cc_rt.obj \
          upfir_df_dblbuf_cr_rt.obj \
          upfir_df_dblbuf_dd_rt.obj \
          upfir_df_dblbuf_dz_rt.obj \
          upfir_df_dblbuf_rc_rt.obj \
          upfir_df_dblbuf_rr_rt.obj \
          upfir_df_dblbuf_zd_rt.obj \
          upfir_df_dblbuf_zz_rt.obj \
          upfirdn_cc_rt.obj \
          upfirdn_cr_rt.obj \
          upfirdn_dd_rt.obj \
          upfirdn_dz_rt.obj \
          upfirdn_rc_rt.obj \
          upfirdn_rr_rt.obj \
          upfirdn_zd_rt.obj \
          upfirdn_zz_rt.obj \
          vfdly_clip_d_rt.obj \
          vfdly_clip_r_rt.obj \
          vfdly_fir_c_rt.obj \
          vfdly_fir_d_rt.obj \
          vfdly_fir_r_rt.obj \
          vfdly_fir_z_rt.obj \
          vfdly_lin_c_rt.obj \
          vfdly_lin_d_rt.obj \
          vfdly_lin_r_rt.obj \
          vfdly_lin_z_rt.obj \
          window_1ch_c_rt.obj \
          window_1ch_d_rt.obj \
          window_1ch_r_rt.obj \
          window_1ch_z_rt.obj \
          window_nch_c_rt.obj \
          window_nch_d_rt.obj \
          window_nch_r_rt.obj \
          window_nch_z_rt.obj \
          

dsp_rt.lib :  $(MAKEFILE) rtw_proj.tmw $(MODULES_dsp_rt)
	@echo ### Creating $@
	@if exist $@ del $@
	$(LIBCMD) /out:$@ $(MODULES_dsp_rt)
	@echo ### Created $@

MODULES_rtwlib = \
          rt_atan2.obj \
          rt_atan232.obj \
          rt_backsubcc_dbl.obj \
          rt_backsubcc_sgl.obj \
          rt_backsubrc_dbl.obj \
          rt_backsubrc_sgl.obj \
          rt_backsubrr_dbl.obj \
          rt_backsubrr_sgl.obj \
          rt_enab.obj \
          rt_forwardsubcc_dbl.obj \
          rt_forwardsubcc_sgl.obj \
          rt_forwardsubcr_dbl.obj \
          rt_forwardsubcr_sgl.obj \
          rt_forwardsubrc_dbl.obj \
          rt_forwardsubrc_sgl.obj \
          rt_forwardsubrr_dbl.obj \
          rt_forwardsubrr_sgl.obj \
          rt_hypot.obj \
          rt_hypot32.obj \
          rt_i32zcfcn.obj \
          rt_intrp1flatcd.obj \
          rt_intrp1flatcf.obj \
          rt_intrp1flatd.obj \
          rt_intrp1flatf.obj \
          rt_intrp1lincd.obj \
          rt_intrp1lincf.obj \
          rt_intrp1linxd.obj \
          rt_intrp1linxf.obj \
          rt_intrp2flatcd.obj \
          rt_intrp2flatcf.obj \
          rt_intrp2flatd.obj \
          rt_intrp2flatf.obj \
          rt_intrp2lincd.obj \
          rt_intrp2lincf.obj \
          rt_intrp2linxd.obj \
          rt_intrp2linxf.obj \
          rt_intrpnflatcd.obj \
          rt_intrpnflatcf.obj \
          rt_intrpnflatd.obj \
          rt_intrpnflatf.obj \
          rt_intrpnlincd.obj \
          rt_intrpnlincf.obj \
          rt_intrpnlind.obj \
          rt_intrpnlinf.obj \
          rt_intrpnlinxd.obj \
          rt_intrpnlinxf.obj \
          rt_intrpnspld.obj \
          rt_intrpnsplf.obj \
          rt_logging.obj \
          rt_look.obj \
          rt_look1d.obj \
          rt_look1d32.obj \
          rt_look2d32_general.obj \
          rt_look2d32_normal.obj \
          rt_look2d_general.obj \
          rt_look2d_normal.obj \
          rt_look32.obj \
          rt_lookflat1bincsd.obj \
          rt_lookflat1bincsf.obj \
          rt_lookflat1binczd.obj \
          rt_lookflat1binczf.obj \
          rt_lookflat1evncsd.obj \
          rt_lookflat1evncsf.obj \
          rt_lookflat1evnczd.obj \
          rt_lookflat1evnczf.obj \
          rt_lookflat1lincsd.obj \
          rt_lookflat1lincsf.obj \
          rt_lookflat1linczd.obj \
          rt_lookflat1linczf.obj \
          rt_lookflat2bincsd.obj \
          rt_lookflat2bincsf.obj \
          rt_lookflat2binczd.obj \
          rt_lookflat2binczf.obj \
          rt_lookflat2evncsd.obj \
          rt_lookflat2evncsf.obj \
          rt_lookflat2evnczd.obj \
          rt_lookflat2evnczf.obj \
          rt_lookflat2lincsd.obj \
          rt_lookflat2lincsf.obj \
          rt_lookflat2linczd.obj \
          rt_lookflat2linczf.obj \
          rt_lookflatnbincsd.obj \
          rt_lookflatnbincsf.obj \
          rt_lookflatnbinczd.obj \
          rt_lookflatnbinczf.obj \
          rt_lookflatnevncsd.obj \
          rt_lookflatnevncsf.obj \
          rt_lookflatnevnczd.obj \
          rt_lookflatnevnczf.obj \
          rt_lookflatnlincsd.obj \
          rt_lookflatnlincsf.obj \
          rt_lookflatnlinczd.obj \
          rt_lookflatnlinczf.obj \
          rt_looklin1bincsd.obj \
          rt_looklin1bincsf.obj \
          rt_looklin1binczd.obj \
          rt_looklin1binczf.obj \
          rt_looklin1binxsd.obj \
          rt_looklin1binxsf.obj \
          rt_looklin1binxzd.obj \
          rt_looklin1binxzf.obj \
          rt_looklin1evncsd.obj \
          rt_looklin1evncsf.obj \
          rt_looklin1evnczd.obj \
          rt_looklin1evnczf.obj \
          rt_looklin1evnxsd.obj \
          rt_looklin1evnxsf.obj \
          rt_looklin1evnxzd.obj \
          rt_looklin1evnxzf.obj \
          rt_looklin1lincsd.obj \
          rt_looklin1lincsf.obj \
          rt_looklin1linczd.obj \
          rt_looklin1linczf.obj \
          rt_looklin1linxsd.obj \
          rt_looklin1linxsf.obj \
          rt_looklin1linxzd.obj \
          rt_looklin1linxzf.obj \
          rt_looklin2bincsd.obj \
          rt_looklin2bincsf.obj \
          rt_looklin2binczd.obj \
          rt_looklin2binczf.obj \
          rt_looklin2binxsd.obj \
          rt_looklin2binxsf.obj \
          rt_looklin2binxzd.obj \
          rt_looklin2binxzf.obj \
          rt_looklin2evncsd.obj \
          rt_looklin2evncsf.obj \
          rt_looklin2evnczd.obj \
          rt_looklin2evnczf.obj \
          rt_looklin2evnxsd.obj \
          rt_looklin2evnxsf.obj \
          rt_looklin2evnxzd.obj \
          rt_looklin2evnxzf.obj \
          rt_looklin2lincsd.obj \
          rt_looklin2lincsf.obj \
          rt_looklin2linczd.obj \
          rt_looklin2linczf.obj \
          rt_looklin2linxsd.obj \
          rt_looklin2linxsf.obj \
          rt_looklin2linxzd.obj \
          rt_looklin2linxzf.obj \
          rt_looklinnbincsd.obj \
          rt_looklinnbincsf.obj \
          rt_looklinnbinczd.obj \
          rt_looklinnbinczf.obj \
          rt_looklinnbinxsd.obj \
          rt_looklinnbinxsf.obj \
          rt_looklinnbinxzd.obj \
          rt_looklinnbinxzf.obj \
          rt_looklinnevncsd.obj \
          rt_looklinnevncsf.obj \
          rt_looklinnevnczd.obj \
          rt_looklinnevnczf.obj \
          rt_looklinnevnxsd.obj \
          rt_looklinnevnxsf.obj \
          rt_looklinnevnxzd.obj \
          rt_looklinnevnxzf.obj \
          rt_looklinnlincsd.obj \
          rt_looklinnlincsf.obj \
          rt_looklinnlinczd.obj \
          rt_looklinnlinczf.obj \
          rt_looklinnlinxsd.obj \
          rt_looklinnlinxsf.obj \
          rt_looklinnlinxzd.obj \
          rt_looklinnlinxzf.obj \
          rt_looksplnbincsd.obj \
          rt_looksplnbincsf.obj \
          rt_looksplnbinczd.obj \
          rt_looksplnbinczf.obj \
          rt_looksplnbinssd.obj \
          rt_looksplnbinssf.obj \
          rt_looksplnbinszd.obj \
          rt_looksplnbinszf.obj \
          rt_looksplnbinxsd.obj \
          rt_looksplnbinxsf.obj \
          rt_looksplnbinxzd.obj \
          rt_looksplnbinxzf.obj \
          rt_looksplnevncsd.obj \
          rt_looksplnevncsf.obj \
          rt_looksplnevnczd.obj \
          rt_looksplnevnczf.obj \
          rt_looksplnevnssd.obj \
          rt_looksplnevnssf.obj \
          rt_looksplnevnszd.obj \
          rt_looksplnevnszf.obj \
          rt_looksplnevnxsd.obj \
          rt_looksplnevnxsf.obj \
          rt_looksplnevnxzd.obj \
          rt_looksplnevnxzf.obj \
          rt_looksplnlincsd.obj \
          rt_looksplnlincsf.obj \
          rt_looksplnlinczd.obj \
          rt_looksplnlinczf.obj \
          rt_looksplnlinssd.obj \
          rt_looksplnlinssf.obj \
          rt_looksplnlinszd.obj \
          rt_looksplnlinszf.obj \
          rt_looksplnlinxsd.obj \
          rt_looksplnlinxsf.obj \
          rt_looksplnlinxzd.obj \
          rt_looksplnlinxzf.obj \
          rt_lu_cplx.obj \
          rt_lu_cplx_sgl.obj \
          rt_lu_real.obj \
          rt_lu_real_sgl.obj \
          rt_matdivcc_dbl.obj \
          rt_matdivcc_sgl.obj \
          rt_matdivcr_dbl.obj \
          rt_matdivcr_sgl.obj \
          rt_matdivrc_dbl.obj \
          rt_matdivrc_sgl.obj \
          rt_matdivrr_dbl.obj \
          rt_matdivrr_sgl.obj \
          rt_matmultandinccc_dbl.obj \
          rt_matmultandinccc_sgl.obj \
          rt_matmultandinccr_dbl.obj \
          rt_matmultandinccr_sgl.obj \
          rt_matmultandincrc_dbl.obj \
          rt_matmultandincrc_sgl.obj \
          rt_matmultandincrr_dbl.obj \
          rt_matmultandincrr_sgl.obj \
          rt_matmultcc_dbl.obj \
          rt_matmultcc_sgl.obj \
          rt_matmultcr_dbl.obj \
          rt_matmultcr_sgl.obj \
          rt_matmultrc_dbl.obj \
          rt_matmultrc_sgl.obj \
          rt_matmultrr_dbl.obj \
          rt_matmultrr_sgl.obj \
          rt_nrand.obj \
          rt_plookbincd.obj \
          rt_plookbincf.obj \
          rt_plookbinkcd.obj \
          rt_plookbinkcf.obj \
          rt_plookbinxd.obj \
          rt_plookbinxf.obj \
          rt_plookevncd.obj \
          rt_plookevncf.obj \
          rt_plookevnkcd.obj \
          rt_plookevnkcf.obj \
          rt_plookevnxd.obj \
          rt_plookevnxf.obj \
          rt_plooklincd.obj \
          rt_plooklincf.obj \
          rt_plooklinkcd.obj \
          rt_plooklinkcf.obj \
          rt_plooklinxd.obj \
          rt_plooklinxf.obj \
          rt_printf.obj \
          rt_sat_div_int16.obj \
          rt_sat_div_int32.obj \
          rt_sat_div_int8.obj \
          rt_sat_div_uint16.obj \
          rt_sat_div_uint32.obj \
          rt_sat_div_uint8.obj \
          rt_sat_prod_int16.obj \
          rt_sat_prod_int32.obj \
          rt_sat_prod_int8.obj \
          rt_sat_prod_uint16.obj \
          rt_sat_prod_uint32.obj \
          rt_sat_prod_uint8.obj \
          rt_tdelay.obj \
          rt_tdelayacc.obj \
          rt_urand.obj \
          rt_zcfcn.obj \
          

rtwlib.lib :  $(MAKEFILE) rtw_proj.tmw $(MODULES_rtwlib)
	@echo ### Creating $@
	@if exist $@ del $@
	$(LIBCMD) /out:$@ $(MODULES_rtwlib)
	@echo ### Created $@



clean :
	@echo ### Deleting the objects and $(PROGRAM)
	@del $(OBJS) ..\$(MODEL)_acc.dll $(wildcard *.obj) $(wildcard *.lib)

#----------------------------- Dependencies -------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw




