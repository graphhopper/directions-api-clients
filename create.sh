#!/bin/bash

SPEC=swagger.json
# SPEC=https://graphhopper.com/api/1/swagger.json
DIR=.

VERSION=0.10-SNAPSHOT

# it is necessary to use the master snapshot to create a proper R and C# client
SW_VERSION=master
#SW_VERSION=2.2.3
FILE=swagger-codegen-cli-$SW_VERSION.jar

NAME=directions-api-client
GROUP=com.graphhopper

if [[ ! -f $FILE ]]; then
  wget http://repo1.maven.org/maven2/io/swagger/swagger-codegen-cli/$SW_VERSION/$FILE -O $FILE
  if [[ ! -f $FILE ]]; then
    curl http://repo1.maven.org/maven2/io/swagger/swagger-codegen-cli/$SW_VERSION/$FILE -O $FILE
  fi
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
		CONFIG="-DgemName=$NAME -DmoduelName=graphhopper_directions_api_client -DgemVersion=$VERSION"
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
  	*)
		;;
  esac

  # echo "create $LANG, config: $CONFIG, additional params: $ADD_PARAMS"
  rm -rf $DIR/$LANG
  SH="java -jar $FILE generate -i $SPEC -l $LANG $CONFIG -o $DIR/$LANG $ADD_PARAMS"
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
  
  create clojure
  create csharp
  create dart
  create go
  create haskell
  create kotlin
  create java
  create nodejs-server
  create objc
  create perl
  create php
  create python
  create qt5cpp
  create r
  create ruby
  create rust
  create scala
  create sinatra
  create swift
  create tizen
fi