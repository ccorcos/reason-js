module Impl (T: { type t; }) => {
  /* baseURI */
  external childNodes : T.t => Dom.nodeList  = "" [@@bs.get];
  external firstChild : T.t => option Dom.node = "" [@@bs.get] [@@bs.return null_to_opt];
  external innerText : T.t => string = "" [@@bs.get];
  external setInnerText : T.t => string => unit = "innerText" [@@bs.set];
  external lastChild : T.t => option Dom.node = "" [@@bs.get];
  external nextSibling : T.t => option Dom.node = "" [@@bs.get] [@@bs.return null_to_opt];
  external nodeName : T.t => string = "" [@@bs.get];
  /* nodePrincipal */
  external nodeType : T.t => int /* nodeType enum */ = "" [@@bs.get];
  let nodeType : T.t => DomTypesRe.nodeType = fun self => DomTypesRe.decodeNodeType (nodeType self);
  external nodeValue : T.t => option string = "" [@@bs.get] [@@bs.return null_to_opt];
  external setNodeValue : T.t => Js.null string => unit = "nodeValue" [@@bs.set];
  /* let setNodeValue : T.t => option string => unit = fun self value => setNodeValue self (Js.Null.from_opt value); */ /* temporarily removed to reduce codegen size */
  /* outerText */
  external ownerDocument : T.t => Dom.document = "" [@@bs.get];
  external parentElement : T.t => option Dom.element = "" [@@bs.get] [@@bs.return null_to_opt];
  external parentNode : T.t => option Dom.node = "" [@@bs.get] [@@bs.return null_to_opt];
  external previousSibling : T.t => option Dom.node = "" [@@bs.get] [@@bs.return null_to_opt];
  external rootNode : T.t => Dom.node = "" [@@bs.get];
  external textContent : T.t => string = "" [@@bs.get];
  external setTextContent : T.t => string => unit = "textContent" [@@bs.set];

  external appendChild : Dom.node_like 'a => unit = "" [@@bs.send.pipe: T.t];
  external cloneNode : Dom.node = "" [@@bs.send.pipe: T.t];
  external cloneNodeDeep : Js.boolean => Dom.node = "cloneNode" [@@bs.send.pipe: T.t];
  /* let cloneNodeDeep : T.t => Dom.node = fun self => cloneNodeDeep Js.true_ self; */ /* temporarily removed to reduce codegen size */
  external compareDocumentPosition : Dom.node_like 'a => int = "" [@@bs.send.pipe: T.t]; /* returns a bitmask which could also be represeneted as an enum, see https://developer.mozilla.org/en-US/docs/Web/API/Node/compareDocumentPosition */
  external contains : Dom.node_like 'a => bool = "" [@@bs.send.pipe: T.t];
  external getRootNode : Dom.node = "" [@@bs.send.pipe: T.t];
  external getRootNodeComposed : Js.boolean => Dom.node = "getRootNode" [@@bs.send.pipe: T.t];
  /* let getRootNodeComposed : T.t => Dom.node = fun self => getRootNodeComposed Js.true_ self; */ /* temporarily removed to reduce codegen size */
  external hasChildNodes : bool = "" [@@bs.send.pipe: T.t];
  external insertBefore : Dom.node_like 'a => Js.null (Dom.node_like 'b) => Dom.node_like 'a = "" [@@bs.send.pipe: T.t];
  let insertBefore : Dom.node_like 'a => option (Dom.node_like 'b) => T.t => Dom.node_like 'a = fun node reference self => insertBefore node (Js.Null.from_opt reference) self;
  external isDefaultNamespace : string => bool = "" [@@bs.send.pipe: T.t];
  external isEqualNode : Dom.node_like 'a => bool = "" [@@bs.send.pipe: T.t];
  external isSameNode : Dom.node_like 'a => bool = "" [@@bs.send.pipe: T.t];
  external lookupNamespaceURI : Js.null string => option string = "" [@@bs.send.pipe: T.t] [@@bs.return null_to_opt];
  /* let lookupNamespaceURI: option string => T.t => option string = fun prefix self => lookupNamespaceURI (Js.Null.from_opt prefix) self; */ /* temporarily removed to reduce codegen size */
  external lookupPrefix : string = "lookupPrefix" [@@bs.send.pipe: T.t];
  external normalize : unit = "" [@@bs.send.pipe: T.t];
  external removeChild : Dom.node_like 'a => Dom.node_like 'a = "" [@@bs.send.pipe: T.t];
  /* replacChild */
};

type t = Dom.node;
include EventTargetRe.Impl { type nonrec t = t };
include Impl { type nonrec t = t };
