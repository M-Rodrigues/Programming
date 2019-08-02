"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
class LinkedListNode {
    constructor(value) {
        this.value = value;
    }
    get Value() { return this.value; }
    set Value(value) { this.value = value; }
    get Next() { return this.next; }
    set Next(n) { this.next = n; }
    showList(l) {
        let arr = [];
        let aux = l;
        while (aux != undefined) {
            arr.push(aux.Value);
            aux = aux.Next;
        }
        return arr;
    }
}
exports.LinkedListNode = LinkedListNode;
const kthToLast = (l, k) => {
    if (k < 0)
        return undefined;
    let size = 0, aux = l;
    while (aux != undefined) {
        aux = aux.Next;
        size++;
    }
    if (size < k)
        return undefined;
    k = size - k;
    aux = l;
    while (k > 0) {
        aux = aux.Next;
        k--;
    }
    return aux;
};
const _main = () => {
    let l = new LinkedListNode(2);
    l.Next = new LinkedListNode(3);
    l.Next.Next = new LinkedListNode(7);
    l.Next.Next.Next = new LinkedListNode(1);
    console.log(l.showList(l));
    console.log(kthToLast(l, 1));
};
_main();
