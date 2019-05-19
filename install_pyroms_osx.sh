# 1. Install
#   - port install gfortran
#   - conda install -c conda-forge lpsolve55
     
# 2. Install
# Activate the Conda python36 environment and set up some handy shell environment variables
# conda activate py37
export SRC=/Users/kokim/Python/ESMG_pyroms
code=cpython-37m-darwin
arch=macosx-10.9-x86_64-3.7
export PREFIX=`which python | xargs dirname | xargs dirname`
export SITE_PACKAGES=${PREFIX}/lib/python3.7/site-packages

# Build and install bathy_smoother
cd $SRC/bathy_smoother
python setup.py build --fcompiler=gnu95
python setup.py install --prefix=${PREFIX}

# Build and install pyroms_toolbox
cd $SRC/pyroms_toolbox
python setup.py build --fcompiler=gnu95
python setup.py install --prefix=${PREFIX}

# Build and install pyroms
cd $SRC/pyroms
python setup.py build --fcompiler=gnu95
python setup.py install --prefix=${PREFIX}

# Build and install nn
#cd $SRC/pyroms/external/nn
#./configure --prefix=${PREFIX}
#make install

# Build and install pyroms_csa
#cd $SRC/pyroms/external/csa
#./configure --prefix=${PREFIX}
#make install

# Build and install gridutils
#cd $SRC/pyroms/external/gridutils
#./configure CPPFLAGS=-I${PREFIX}/include LDFLAGS=-L${PREFIX}/lib CFLAGS=-I${PREFIX}/include --prefix=${PREFIX}
#make install

# Build and install gridgen
#cd $SRC/pyroms/external/gridgen
#export SHLIBS=-L${PREFIX}/lib
#./configure CPPFLAGS=-I${PREFIX}/include LDFLAGS=-L${PREFIX}/lib CFLAGS=-I${PREFIX}/include --prefix=${PREFIX}
#make
#make lib
#make shlib
#make install

# Build and install scrip. The netCDF configuration is passed explicity via command-line
# variables because nf-config is broken on CentOS 7. The "-j 1" may or may not be needed 
# to work around broken dependencies in the make file.
cd $SRC/pyroms/external/scrip/source
make -j 1 PREFIX=${PREFIX} LIBDIR=${PREFIX}/lib INCDIR=${PREFIX}/include LIB="-lnetcdff -lnetcdf -L${PREFIX}/lib" all f2py
make -j 1 PREFIX=${PREFIX} LIBDIR=${PREFIX}/lib INCDIR=${PREFIX}/include LIB="-lnetcdff -lnetcdf -L${PREFIX}/lib" install

# Copy dynamic libraries to the site-packages directory. They are copied one at a time
# so I can keep track of which ones have been copied.
#cd $SRC
#cp -v ./pyroms/external/gridutils/libgu.so $SITE_PACKAGES
#cp -v ./pyroms/external/gridgen/libgridgen.so $SITE_PACKAGES
#cp -v ./pyroms/external/scrip/source/scrip.${code}.so $SITE_PACKAGES
#cp -v ./pyroms/build/lib.${arch}/pyroms/_remapping_fast.${code}.so $SITE_PACKAGES
#cp -v ./pyroms/build/lib.${arch}/pyroms/_interp.${code}.so $SITE_PACKAGES
##cp -v ./pyroms/build/lib.${arch}/pyroms/_obs_interp.${code}.so $SITE_PACKAGES
#cp -v ./pyroms/build/lib.${arch}/pyroms/_remapping_fast_weighted.${code}.so $SITE_PACKAGES
#cp -v ./pyroms/build/lib.${arch}/pyroms/_remapping.${code}.so $SITE_PACKAGES
#cp -v ./pyroms/build/lib.${arch}/pyroms/_iso.${code}.so $SITE_PACKAGES
#cp -v ./pyroms_toolbox/build/lib.${arch}/pyroms_toolbox/creep.${code}.so $SITE_PACKAGES
#cp -v ./pyroms_toolbox/build/lib.${arch}/pyroms_toolbox/_move_runoff.${code}.so $SITE_PACKAGES
#cp -v ./pyroms_toolbox/build/lib.${arch}/pyroms_toolbox/_average.${code}.so $SITE_PACKAGES
##cp -v ./pyroms_toolbox/build/lib.${arch}/pyroms_toolbox/_move_river_t.${code}.so $SITE_PACKAGES
