type t = Dom.selection;

external anchorNode : t => Dom.node = "" [@@bs.get];
external anchorOffset : t => int = "" [@@bs.get];
external focusNode : t => Dom.node = "" [@@bs.get];
external focusOffset : t => int = "" [@@bs.get];
external isCollapsed : t => bool = "" [@@bs.get];
external rangeCount : t => int = "" [@@bs.get];

external getRangeAt : int => Dom.range = "" [@@bs.send.pipe: t];
external collapse : Dom.node_like _ => int => unit = "" [@@bs.send.pipe: t];
external extend : Dom.node_like _ => int => unit = "" [@@bs.send.pipe: t];
external collapseToStart : unit = "" [@@bs.send.pipe: t];
external collapseToEnd : unit = "" [@@bs.send.pipe: t];
external selectAllChildren : Dom.node_like _ => unit = "" [@@bs.send.pipe: t];
external addRange : Dom.range => unit = "" [@@bs.send.pipe: t];
external removeRange : Dom.range => unit = "" [@@bs.send.pipe: t];
external removeAllRanges : unit = "" [@@bs.send.pipe: t];
external deleteFromDocument : unit = "" [@@bs.send.pipe: t];
external toString : string = "" [@@bs.send.pipe: t];
external containsNode : Dom.node_like _ => Js.boolean => bool= "" [@@bs.send.pipe: t];
let containsNode : Dom.node_like _ => bool => t => bool = fun node partlyContained self => containsNode node (Js.Boolean.to_js_boolean partlyContained) self;
