# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.unit-tests.Debug:
/Users/johnseol/snake-linked-list-jseol073/Debug/unit-tests:
	/bin/rm -f /Users/johnseol/snake-linked-list-jseol073/Debug/unit-tests


PostBuild.unit-tests.Release:
/Users/johnseol/snake-linked-list-jseol073/Release/unit-tests:
	/bin/rm -f /Users/johnseol/snake-linked-list-jseol073/Release/unit-tests


PostBuild.unit-tests.MinSizeRel:
/Users/johnseol/snake-linked-list-jseol073/MinSizeRel/unit-tests:
	/bin/rm -f /Users/johnseol/snake-linked-list-jseol073/MinSizeRel/unit-tests


PostBuild.unit-tests.RelWithDebInfo:
/Users/johnseol/snake-linked-list-jseol073/RelWithDebInfo/unit-tests:
	/bin/rm -f /Users/johnseol/snake-linked-list-jseol073/RelWithDebInfo/unit-tests




# For each target create a dummy ruleso the target does not have to exist
