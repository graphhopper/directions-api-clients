#!/bin/bash

# currently must be available locally as we need to do "sed" stuff
SPEC=openapi.yaml
DIR=.

VERSION=0.13.0-pre1

SW_VERSION=3.0.11
FILE=swagger-codegen-cli-$SW_VERSION.jar

NAME=directions-api-client
GROUP=com.graphhopper

if [[ ! -s $FILE ]]; then
  wget https://graphhopper.com/public/misc/$FILE -O $FILE
  if [[ ! -s $FILE ]]; then
    wget http://repo1.maven.org/maven2/io/swagger/codegen/v3/swagger-codegen-cli/$SW_VERSION/$FILE -O $FILE
    if [[ ! -s $FILE ]]; then
      curl http://repo1.maven.org/maven2/io/swagger/codegen/v3/swagger-codegen-cli/$SW_VERSION/$FILE -O $FILE
    fi
  fi
fi

file_size_kb=$(du -k "$FILE" | cut -f1)
if [[ $file_size_kb -lt 1000 ]]; then
  echo corrupt file $FILE, remove it, ensure host exists and try again
  exit
fi

function create {
  LANG=$1
  CONFIG=""
  ADD_PARAMS=""

  case "$LANG" in
	java)
		PKG="com.graphhopper.directions.api.client"
		CONFIG="--artifact-version $VERSION --api-package $PKG.api --invoker-package $PKG --model-package $PKG.model --artifact-id $NAME --group-id $GROUP --library okhttp-gson -DhideGenerationTimestamp=true"
		;;
	ruby)
		CONFIG="-DgemName=$NAME -DmoduleName=GraphHopperClient -DgemVersion=$VERSION"
		;;
	go)
		# CONFIG="-t modules/swagger-codegen/src/main/resources/go"
		ADD_PARAMS="-DpackageName=graphhopper"
		;;
	swift)
		CONFIG="-DprojectName=GraphHopper"
		;;
	javascript)
		CONFIG="-t modules/swagger-codegen/src/main/resources/Javascript"
		;;
	haskell)
		;;
	r)
		ADD_PARAMS="-DpackageName=GraphHopper"
		;;
	php)
		CONFIG="--artifact-version $VERSION --git-repo-id $NAME --git-user-id graphhopper --api-package $NAME"
		;;
	csharp)
		VER=$(echo $VERSION | cut -d'-' -f 1)
		ADD_PARAMS="-DpackageName=GraphHopper,packageVersion=$VER"
		;;
  	*)
		;;
  esac

  # This is ugly. The name of our endpoint is "Matrix API" and swagger codegen creates classes like MatrixApiApi and we just want MatrixApi for backward compatibility
#  cat $SPEC | sed -e 's/Matrix API/Matrix/g' | sed -e 's/Routing API/Routing/g' | sed -e 's/Geocoding API/Geocoding/g' | sed -e 's/Route Optimization API/Route Optimization/g' | sed -e 's/Map Matching API/Map Matching/g' | sed -e 's/Isochrone API/Isochrone/g' > openapi_tmp.yaml
  SH="java -jar $FILE generate -i openapi_tmp.yaml -l $LANG $CONFIG -o $DIR/$LANG $ADD_PARAMS"
  echo $SH
  $SH
}

LANG=$1
if [[ "$LANG" != "" ]]; then
  create $LANG
  exit 0
else
  echo "creating all"
  
  # the JS client is just too large and not recommended so use nodejs-server
  # create javascript -> nodejs-server
  
  create csharp
  create java
  create kotlin-client
  create nodejs-server
  create php
  create python
  create scala
  create swift4
fi
