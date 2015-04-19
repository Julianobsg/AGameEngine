#echo `pwd `
#echo `type -a newagameengine.sh`
dirname=`perl -e 'use Cwd "abs_path";print abs_path(shift)' $0`
#echo $dirname

scriptDir="$(cd "$(dirname "$0")" && pwd -P)"
#echo $scriptDir

gradle="$scriptDir/gradlew"

buildFile="$scriptDir/build.gradle"
#echo $gradle
#$gradle tasks
$gradle -q -b $buildFile -Pparam=$2 $1