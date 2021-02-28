--test.lua

function hoge( ... )
	-- body
	coroutine.yield("•¶1")
	coroutine.yield("•¶2")
	coroutine.yield("•¶3")
	return ""
end
