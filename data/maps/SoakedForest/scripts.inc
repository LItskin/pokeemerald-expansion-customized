.set LOCALID_GARDENIA, 1

SoakedForest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SoakedForest_OnTransition
	.byte 0

SoakedForest_OnTransition:
	call_if_set FLAG_GARDENIA_MOVED, SoakedForset_EventScript_MoveGardenia
	end

SoakedForest_EventScript_Gardenia::
	lock
	faceplayer
	checktrainerflag TRAINER_GARDENIA_1
	goto_if_eq VAR_RESULT, TRUE, SoakedForest_EventScript_GardeniaRefight
	msgbox SoakedForest_Text_Gardenia_Fight1YN, MSGBOX_YESNO
	goto_if_eq 0 SoakedForest_EventScript_GardeniaIllBeHere
	trainerbattle_single TRAINER_GARDENIA_1, SoakedForest_Text_Gardenia1Intro, SoakedForest_Text_Gardenia1Defeated, SoakedForest_EventScript_Gardenia1Defeated
	release
	end

SoakedForest_EventScript_GardeniaIllBeHere::
	msgbox SoakedForest_Text_GardeniaIllBeHere
	release
	end

SoakedForest_Text_Gardenia_Fight1YN:
	.string "Gardenia: Heya there trainer!\p"
	.string "You don't find to many people in a\n"
	.string "Seclued place like this.\p"
	.string "Me? I've traveled from Sinnoh to become\n"
	.string "stronger with my GRASS-type POKéMON.\p"
	.string "I usually use bright sunlight to my\n"
	.string "advantage, so I came here to this forest\l"
	.string "where the water dripping from the trees\n"
	.string "makes it seem like it is always raining.\p"
	.string "Would you like to see the fruits of my\n"
	.string "training? My team is at about the strength\l"
	.string "of a trainer with three gym badges.$"

SoakedForest_Text_Gardenia1Intro:
	.string "Prepare to face the wildflower of\n"
	.string "Eterna City!$"

SoakedForest_Text_Gardenia1Defeated:
	.string "Congradulations! I won't let this defeat\n"
	.string "rain on my spirit. You have trained your\l"
	.string "POKéMON well, and that's more then enough\l"
	.string "inspiration to get me back into my training.$"

SoakedForest_Text_GardeniaIllBeHere:
	.string "Too bad. I'll be herer if you change your\n"
	.string "mind.$"

SoakedForest_EventScript_Gardenia1Defeated::
	msgbox SoakedForest_Text_Gardenia1Reward, MSGBOX_DEFAULT
	giveitem ITEM_GRASSIUM_Z
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GRASS_Z_CRYSTAL
	msgbox SoakedForest_Text_GardeniaReturn, MSGBOX_DEFAULT
	release
	end

SoakedForest_Text_Gardenia1Reward:
	.string "Here is a reward for such a great battle:\n"
	.string "It's a Z-CRYSTAL, a special type of stone\l"
	.string "that when combined with a Z-RING lets a\l"
	.string "POKéMON that hold it and has a GRASS-type\l"
	.string "move perform wonderful BLOOM DOOM!$"

SoakedForest_Text_GardeniaReturn:
	.string "Come back when you are much stronger and\n"
	.string "we can have a full powered match with my\l"
	.string "strongest POKéMON.$"

SoakedForest_EventScript_GardeniaRefight::
	call_if_unset FLAG_GRASS_Z_CRYSTAL, SoakedForest_EventScript_Gardenia1Defeated
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, SoakedForest_EventScript_Gardenia_ComeBackLater
	checktrainerflag TRAINER_GARDENIA_2
	goto_if_eq VAR_RESULT, TRUE, SoakedForest_EventScript_Gardenia2Defeated
	msgbox SoakedForest_Text_Gardenia_Fight2YN, MSGBOX_YESNO
	goto_if_eq 0 SoakedForest_EventScript_GardeniaIllBeHere
	trainerbattle_single TRAINER_GARDENIA_2, SoakedForest_Text_Gardenia2Intro, SoakedForest_Text_Gardenia2Defeated, SoakedForest_EventScript_Gardenia2Defeated
	release
	end

SoakedForest_EventScript_Gardenia_ComeBackLater::
	msgbox SoakedForest_Text_GardeniaReturn, MSGBOX_DEFAULT
	release
	end

SoakedForest_Text_Gardenia_Fight2YN:
	.string "Gardenia: I heard that you have become this\n"
	.string "region's CHAMPION.\p"
	.string "Are you ready to face me and my POKéMON at\n"
	.string "their strongest?$"

SoakedForest_Text_Gardenia2Intro:
	.string "Witness the wildflower of Eterna City at\n"
	.string "her most beautiful bloom yet!$"

SoakedForest_Text_Gardenia2Defeated:
	.string "Defeated again. You sure are something.$"

SoakedForest_EventScript_Gardenia2Defeated::
	msgbox SoakedForest_Text_GardeniaEnterShrine, MSGBOX_DEFAULT
	goto_if_set FLAG_GARDENIA_MOVED, SoakedForest_EventScript_GardeniaFinal
	applymovement LOCALID_GARDENIA, SoakedForest_Movement_Gardenia
	setflag FLAG_GARDENIA_MOVED
	goto SoakedForest_EventScript_GardeniaFinal

SoakedForest_EventScript_GardeniaFinal::
	msgbox SoakedForest_Text_GardeniaFinal, MSGBOX_DEFAULT
	release
	end

SoakedForest_Movement_Gardenia:
	walk_right
	walk_in_place_faster_left
	step_end

SoakedForest_Text_GardeniaEnterShrine:
	.string "I bet you're wondering what this little\n"
	.string "cave behind me is.\p"
	.string "It's a little shrine to a very rare POKéMON.\n"
	.string "It's actually the reason why I came here.\p"
	.string "I heard stories of a mythical GRASS-type\n"
	.string "POKéMON and I came to check it out.\p"
	.string "However...\p"
	.string "Since you beat me, I'll let you go meet\n"
	.string "that POKéMON first.$"

SoakedForest_Text_GardeniaFinal:
	.string "You know what, I'll just stay out here.\p"
	.string "I've felt a chilly aura coming from the\n"
	.string "cave.\p"
	.string "I don't think I'm prepared for the mythical\n"
	.string "GRASS-type pokemon to be also GHOST-type.$"

SoakedForset_EventScript_MoveGardenia:
	setobjectxyperm LOCALID_GARDENIA, 26, 4
	return
